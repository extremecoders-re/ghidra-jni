# ghidra-jni

All in-one `jni.h` compiled for Ghidra. 

## How to load in Ghidra?

Go to `File -> Parse C Source`

Create a new Parse Configuration Profile with the following Parse Options

```
-D_X86_
-D__STDC__
-D_GNU_SOURCE
-D__WORDSIZE=64
-Dva_list=void *
-D__DO_NOT_DEFINE_COMPILE
-D_Complex
-D_WCHAR_T
-D__NO_STRING_INLINES
-D__signed__
-D__extension__=""
-D_Bool="bool"
-D__GLIBC_HAVE_LONG_LONG=1
-D__need_sigset_t
-Daligned_u64=uint64_t
-Daligned_u64=uint64_t
```
Under source files to parse, add `jni-ghidra.h` to the list. Remove any other existing file (if any).

## How was this generated ?

The default `jni.h` from Java fails to parse correctly in Ghidra. As a result, I have taken a precompiled `jni.h` intended for IDA Pro from [here](https://gist.github.com/Jinmo/048776db75067dcd6c57f1154e65b868) and pre-processed it (`gcc -E`/`cpp`). The pre-processed file contain several lines begining with `#` which correspond to source files. These lines must be removed or else Ghidra will fail to parse.

As a result of pre-processing this does not contain C++ definitions for the various JNI types. If you want C++ type definitions as well use the one intended for IDA Pro.

## Useful Info 

### Adding a function data type using the API

A function data type can also be added using the Ghidra Python API. An example is shown below

```python
from ghidra.app.util.cparser.C.CParserUtils import parseSignature
from ghidra.program.model.data import DataTypeConflictHandler 

fn_sign = 'void function1(int p1, int p2)'
fn_defn = parseSignature(None, currentProgram, fn_sign)
dtm = currentProgram.getDataTypeManager()
dtm.addDataType(fn_defn, DataTypeConflictHandler.DEFAULT_HANDLER)
```

### Creating structures programmatically

From my answer on [RE.SE](https://reverseengineering.stackexchange.com/a/23373/1413)

```
from ghidra.program.model.data import DataTypeConflictHandler
from ghidra.app.util.cparser.C import CParser

mystruct_txt = """
struct mystruct{
    uint32_t field1; 
    uint32_t field2;
};"""

# Get Data Type Manager
data_type_manager = currentProgram.getDataTypeManager()

# Create CParser
parser = CParser(data_type_manager)

# Parse structure
parsed_datatype = parser.parse(mystruct_txt)

# Add parsed type to data type manager
data_type_manager.addDataType(parsed_datatype, DataTypeConflictHandler.DEFAULT_HANDLER)
```
