typedef long jint;
typedef __int64 jlong;
typedef signed char jbyte;
typedef unsigned char jboolean;
typedef unsigned short jchar;
typedef short jshort;
typedef float jfloat;
typedef double jdouble;

typedef jint jsize;
struct _jobject;

typedef struct _jobject *jobject;
typedef jobject jclass;
typedef jobject jthrowable;
typedef jobject jstring;
typedef jobject jarray;
typedef jarray jbooleanArray;
typedef jarray jbyteArray;
typedef jarray jcharArray;
typedef jarray jshortArray;
typedef jarray jintArray;
typedef jarray jlongArray;
typedef jarray jfloatArray;
typedef jarray jdoubleArray;
typedef jarray jobjectArray;



typedef jobject jweak;

typedef union jvalue {
    jboolean z;
    jbyte b;
    jchar c;
    jshort s;
    jint i;
    jlong j;
    jfloat f;
    jdouble d;
    jobject l;
} jvalue;

struct _jfieldID;
typedef struct _jfieldID *jfieldID;

struct _jmethodID;
typedef struct _jmethodID *jmethodID;


typedef enum _jobjectType {
     JNIInvalidRefType = 0,
     JNILocalRefType = 1,
     JNIGlobalRefType = 2,
     JNIWeakGlobalRefType = 3
} jobjectRefType;
typedef struct {
    char *name;
    char *signature;
    void *fnPtr;
} JNINativeMethod;





struct JNINativeInterface_;

struct JNIEnv_;




typedef const struct JNINativeInterface_ *JNIEnv;






struct JNIInvokeInterface_;

struct JavaVM_;




typedef const struct JNIInvokeInterface_ *JavaVM;


struct JNINativeInterface_ {
    void *reserved0;
    void *reserved1;
    void *reserved2;

    void *reserved3;
    jint (__stdcall *GetVersion)(JNIEnv *env);

    jclass (__stdcall *DefineClass)
      (JNIEnv *env, const char *name, jobject loader, const jbyte *buf,
       jsize len);
    jclass (__stdcall *FindClass)
      (JNIEnv *env, const char *name);

    jmethodID (__stdcall *FromReflectedMethod)
      (JNIEnv *env, jobject method);
    jfieldID (__stdcall *FromReflectedField)
      (JNIEnv *env, jobject field);

    jobject (__stdcall *ToReflectedMethod)
      (JNIEnv *env, jclass cls, jmethodID methodID, jboolean isStatic);

    jclass (__stdcall *GetSuperclass)
      (JNIEnv *env, jclass sub);
    jboolean (__stdcall *IsAssignableFrom)
      (JNIEnv *env, jclass sub, jclass sup);

    jobject (__stdcall *ToReflectedField)
      (JNIEnv *env, jclass cls, jfieldID fieldID, jboolean isStatic);

    jint (__stdcall *Throw)
      (JNIEnv *env, jthrowable obj);
    jint (__stdcall *ThrowNew)
      (JNIEnv *env, jclass clazz, const char *msg);
    jthrowable (__stdcall *ExceptionOccurred)
      (JNIEnv *env);
    void (__stdcall *ExceptionDescribe)
      (JNIEnv *env);
    void (__stdcall *ExceptionClear)
      (JNIEnv *env);
    void (__stdcall *FatalError)
      (JNIEnv *env, const char *msg);

    jint (__stdcall *PushLocalFrame)
      (JNIEnv *env, jint capacity);
    jobject (__stdcall *PopLocalFrame)
      (JNIEnv *env, jobject result);

    jobject (__stdcall *NewGlobalRef)
      (JNIEnv *env, jobject lobj);
    void (__stdcall *DeleteGlobalRef)
      (JNIEnv *env, jobject gref);
    void (__stdcall *DeleteLocalRef)
      (JNIEnv *env, jobject obj);
    jboolean (__stdcall *IsSameObject)
      (JNIEnv *env, jobject obj1, jobject obj2);
    jobject (__stdcall *NewLocalRef)
      (JNIEnv *env, jobject ref);
    jint (__stdcall *EnsureLocalCapacity)
      (JNIEnv *env, jint capacity);

    jobject (__stdcall *AllocObject)
      (JNIEnv *env, jclass clazz);
    jobject (__stdcall *NewObject)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jobject (__stdcall *NewObjectV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jobject (__stdcall *NewObjectA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jclass (__stdcall *GetObjectClass)
      (JNIEnv *env, jobject obj);
    jboolean (__stdcall *IsInstanceOf)
      (JNIEnv *env, jobject obj, jclass clazz);

    jmethodID (__stdcall *GetMethodID)
      (JNIEnv *env, jclass clazz, const char *name, const char *sig);

    jobject (__stdcall *CallObjectMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jobject (__stdcall *CallObjectMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jobject (__stdcall *CallObjectMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue * args);

    jboolean (__stdcall *CallBooleanMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jboolean (__stdcall *CallBooleanMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jboolean (__stdcall *CallBooleanMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue * args);

    jbyte (__stdcall *CallByteMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jbyte (__stdcall *CallByteMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jbyte (__stdcall *CallByteMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    jchar (__stdcall *CallCharMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jchar (__stdcall *CallCharMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jchar (__stdcall *CallCharMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    jshort (__stdcall *CallShortMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jshort (__stdcall *CallShortMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jshort (__stdcall *CallShortMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    jint (__stdcall *CallIntMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jint (__stdcall *CallIntMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jint (__stdcall *CallIntMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    jlong (__stdcall *CallLongMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jlong (__stdcall *CallLongMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jlong (__stdcall *CallLongMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    jfloat (__stdcall *CallFloatMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jfloat (__stdcall *CallFloatMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jfloat (__stdcall *CallFloatMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    jdouble (__stdcall *CallDoubleMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jdouble (__stdcall *CallDoubleMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jdouble (__stdcall *CallDoubleMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    void (__stdcall *CallVoidMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    void (__stdcall *CallVoidMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    void (__stdcall *CallVoidMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue * args);

    jobject (__stdcall *CallNonvirtualObjectMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jobject (__stdcall *CallNonvirtualObjectMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jobject (__stdcall *CallNonvirtualObjectMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue * args);

    jboolean (__stdcall *CallNonvirtualBooleanMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jboolean (__stdcall *CallNonvirtualBooleanMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jboolean (__stdcall *CallNonvirtualBooleanMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue * args);

    jbyte (__stdcall *CallNonvirtualByteMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jbyte (__stdcall *CallNonvirtualByteMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jbyte (__stdcall *CallNonvirtualByteMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    jchar (__stdcall *CallNonvirtualCharMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jchar (__stdcall *CallNonvirtualCharMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jchar (__stdcall *CallNonvirtualCharMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    jshort (__stdcall *CallNonvirtualShortMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jshort (__stdcall *CallNonvirtualShortMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jshort (__stdcall *CallNonvirtualShortMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    jint (__stdcall *CallNonvirtualIntMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jint (__stdcall *CallNonvirtualIntMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jint (__stdcall *CallNonvirtualIntMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    jlong (__stdcall *CallNonvirtualLongMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jlong (__stdcall *CallNonvirtualLongMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jlong (__stdcall *CallNonvirtualLongMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    jfloat (__stdcall *CallNonvirtualFloatMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jfloat (__stdcall *CallNonvirtualFloatMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jfloat (__stdcall *CallNonvirtualFloatMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    jdouble (__stdcall *CallNonvirtualDoubleMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jdouble (__stdcall *CallNonvirtualDoubleMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jdouble (__stdcall *CallNonvirtualDoubleMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    void (__stdcall *CallNonvirtualVoidMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    void (__stdcall *CallNonvirtualVoidMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    void (__stdcall *CallNonvirtualVoidMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue * args);

    jfieldID (__stdcall *GetFieldID)
      (JNIEnv *env, jclass clazz, const char *name, const char *sig);

    jobject (__stdcall *GetObjectField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jboolean (__stdcall *GetBooleanField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jbyte (__stdcall *GetByteField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jchar (__stdcall *GetCharField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jshort (__stdcall *GetShortField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jint (__stdcall *GetIntField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jlong (__stdcall *GetLongField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jfloat (__stdcall *GetFloatField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jdouble (__stdcall *GetDoubleField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);

    void (__stdcall *SetObjectField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jobject val);
    void (__stdcall *SetBooleanField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jboolean val);
    void (__stdcall *SetByteField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jbyte val);
    void (__stdcall *SetCharField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jchar val);
    void (__stdcall *SetShortField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jshort val);
    void (__stdcall *SetIntField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jint val);
    void (__stdcall *SetLongField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jlong val);
    void (__stdcall *SetFloatField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jfloat val);
    void (__stdcall *SetDoubleField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jdouble val);

    jmethodID (__stdcall *GetStaticMethodID)
      (JNIEnv *env, jclass clazz, const char *name, const char *sig);

    jobject (__stdcall *CallStaticObjectMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jobject (__stdcall *CallStaticObjectMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jobject (__stdcall *CallStaticObjectMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jboolean (__stdcall *CallStaticBooleanMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jboolean (__stdcall *CallStaticBooleanMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jboolean (__stdcall *CallStaticBooleanMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jbyte (__stdcall *CallStaticByteMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jbyte (__stdcall *CallStaticByteMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jbyte (__stdcall *CallStaticByteMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jchar (__stdcall *CallStaticCharMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jchar (__stdcall *CallStaticCharMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jchar (__stdcall *CallStaticCharMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jshort (__stdcall *CallStaticShortMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jshort (__stdcall *CallStaticShortMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jshort (__stdcall *CallStaticShortMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jint (__stdcall *CallStaticIntMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jint (__stdcall *CallStaticIntMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jint (__stdcall *CallStaticIntMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jlong (__stdcall *CallStaticLongMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jlong (__stdcall *CallStaticLongMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jlong (__stdcall *CallStaticLongMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jfloat (__stdcall *CallStaticFloatMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jfloat (__stdcall *CallStaticFloatMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jfloat (__stdcall *CallStaticFloatMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jdouble (__stdcall *CallStaticDoubleMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jdouble (__stdcall *CallStaticDoubleMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jdouble (__stdcall *CallStaticDoubleMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    void (__stdcall *CallStaticVoidMethod)
      (JNIEnv *env, jclass cls, jmethodID methodID, ...);
    void (__stdcall *CallStaticVoidMethodV)
      (JNIEnv *env, jclass cls, jmethodID methodID, va_list args);
    void (__stdcall *CallStaticVoidMethodA)
      (JNIEnv *env, jclass cls, jmethodID methodID, const jvalue * args);

    jfieldID (__stdcall *GetStaticFieldID)
      (JNIEnv *env, jclass clazz, const char *name, const char *sig);
    jobject (__stdcall *GetStaticObjectField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jboolean (__stdcall *GetStaticBooleanField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jbyte (__stdcall *GetStaticByteField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jchar (__stdcall *GetStaticCharField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jshort (__stdcall *GetStaticShortField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jint (__stdcall *GetStaticIntField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jlong (__stdcall *GetStaticLongField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jfloat (__stdcall *GetStaticFloatField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jdouble (__stdcall *GetStaticDoubleField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);

    void (__stdcall *SetStaticObjectField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jobject value);
    void (__stdcall *SetStaticBooleanField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jboolean value);
    void (__stdcall *SetStaticByteField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jbyte value);
    void (__stdcall *SetStaticCharField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jchar value);
    void (__stdcall *SetStaticShortField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jshort value);
    void (__stdcall *SetStaticIntField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jint value);
    void (__stdcall *SetStaticLongField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jlong value);
    void (__stdcall *SetStaticFloatField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jfloat value);
    void (__stdcall *SetStaticDoubleField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jdouble value);

    jstring (__stdcall *NewString)
      (JNIEnv *env, const jchar *unicode, jsize len);
    jsize (__stdcall *GetStringLength)
      (JNIEnv *env, jstring str);
    const jchar *(__stdcall *GetStringChars)
      (JNIEnv *env, jstring str, jboolean *isCopy);
    void (__stdcall *ReleaseStringChars)
      (JNIEnv *env, jstring str, const jchar *chars);

    jstring (__stdcall *NewStringUTF)
      (JNIEnv *env, const char *utf);
    jsize (__stdcall *GetStringUTFLength)
      (JNIEnv *env, jstring str);
    const char* (__stdcall *GetStringUTFChars)
      (JNIEnv *env, jstring str, jboolean *isCopy);
    void (__stdcall *ReleaseStringUTFChars)
      (JNIEnv *env, jstring str, const char* chars);


    jsize (__stdcall *GetArrayLength)
      (JNIEnv *env, jarray array);

    jobjectArray (__stdcall *NewObjectArray)
      (JNIEnv *env, jsize len, jclass clazz, jobject init);
    jobject (__stdcall *GetObjectArrayElement)
      (JNIEnv *env, jobjectArray array, jsize index);
    void (__stdcall *SetObjectArrayElement)
      (JNIEnv *env, jobjectArray array, jsize index, jobject val);

    jbooleanArray (__stdcall *NewBooleanArray)
      (JNIEnv *env, jsize len);
    jbyteArray (__stdcall *NewByteArray)
      (JNIEnv *env, jsize len);
    jcharArray (__stdcall *NewCharArray)
      (JNIEnv *env, jsize len);
    jshortArray (__stdcall *NewShortArray)
      (JNIEnv *env, jsize len);
    jintArray (__stdcall *NewIntArray)
      (JNIEnv *env, jsize len);
    jlongArray (__stdcall *NewLongArray)
      (JNIEnv *env, jsize len);
    jfloatArray (__stdcall *NewFloatArray)
      (JNIEnv *env, jsize len);
    jdoubleArray (__stdcall *NewDoubleArray)
      (JNIEnv *env, jsize len);

    jboolean * (__stdcall *GetBooleanArrayElements)
      (JNIEnv *env, jbooleanArray array, jboolean *isCopy);
    jbyte * (__stdcall *GetByteArrayElements)
      (JNIEnv *env, jbyteArray array, jboolean *isCopy);
    jchar * (__stdcall *GetCharArrayElements)
      (JNIEnv *env, jcharArray array, jboolean *isCopy);
    jshort * (__stdcall *GetShortArrayElements)
      (JNIEnv *env, jshortArray array, jboolean *isCopy);
    jint * (__stdcall *GetIntArrayElements)
      (JNIEnv *env, jintArray array, jboolean *isCopy);
    jlong * (__stdcall *GetLongArrayElements)
      (JNIEnv *env, jlongArray array, jboolean *isCopy);
    jfloat * (__stdcall *GetFloatArrayElements)
      (JNIEnv *env, jfloatArray array, jboolean *isCopy);
    jdouble * (__stdcall *GetDoubleArrayElements)
      (JNIEnv *env, jdoubleArray array, jboolean *isCopy);

    void (__stdcall *ReleaseBooleanArrayElements)
      (JNIEnv *env, jbooleanArray array, jboolean *elems, jint mode);
    void (__stdcall *ReleaseByteArrayElements)
      (JNIEnv *env, jbyteArray array, jbyte *elems, jint mode);
    void (__stdcall *ReleaseCharArrayElements)
      (JNIEnv *env, jcharArray array, jchar *elems, jint mode);
    void (__stdcall *ReleaseShortArrayElements)
      (JNIEnv *env, jshortArray array, jshort *elems, jint mode);
    void (__stdcall *ReleaseIntArrayElements)
      (JNIEnv *env, jintArray array, jint *elems, jint mode);
    void (__stdcall *ReleaseLongArrayElements)
      (JNIEnv *env, jlongArray array, jlong *elems, jint mode);
    void (__stdcall *ReleaseFloatArrayElements)
      (JNIEnv *env, jfloatArray array, jfloat *elems, jint mode);
    void (__stdcall *ReleaseDoubleArrayElements)
      (JNIEnv *env, jdoubleArray array, jdouble *elems, jint mode);

    void (__stdcall *GetBooleanArrayRegion)
      (JNIEnv *env, jbooleanArray array, jsize start, jsize l, jboolean *buf);
    void (__stdcall *GetByteArrayRegion)
      (JNIEnv *env, jbyteArray array, jsize start, jsize len, jbyte *buf);
    void (__stdcall *GetCharArrayRegion)
      (JNIEnv *env, jcharArray array, jsize start, jsize len, jchar *buf);
    void (__stdcall *GetShortArrayRegion)
      (JNIEnv *env, jshortArray array, jsize start, jsize len, jshort *buf);
    void (__stdcall *GetIntArrayRegion)
      (JNIEnv *env, jintArray array, jsize start, jsize len, jint *buf);
    void (__stdcall *GetLongArrayRegion)
      (JNIEnv *env, jlongArray array, jsize start, jsize len, jlong *buf);
    void (__stdcall *GetFloatArrayRegion)
      (JNIEnv *env, jfloatArray array, jsize start, jsize len, jfloat *buf);
    void (__stdcall *GetDoubleArrayRegion)
      (JNIEnv *env, jdoubleArray array, jsize start, jsize len, jdouble *buf);

    void (__stdcall *SetBooleanArrayRegion)
      (JNIEnv *env, jbooleanArray array, jsize start, jsize l, const jboolean *buf);
    void (__stdcall *SetByteArrayRegion)
      (JNIEnv *env, jbyteArray array, jsize start, jsize len, const jbyte *buf);
    void (__stdcall *SetCharArrayRegion)
      (JNIEnv *env, jcharArray array, jsize start, jsize len, const jchar *buf);
    void (__stdcall *SetShortArrayRegion)
      (JNIEnv *env, jshortArray array, jsize start, jsize len, const jshort *buf);
    void (__stdcall *SetIntArrayRegion)
      (JNIEnv *env, jintArray array, jsize start, jsize len, const jint *buf);
    void (__stdcall *SetLongArrayRegion)
      (JNIEnv *env, jlongArray array, jsize start, jsize len, const jlong *buf);
    void (__stdcall *SetFloatArrayRegion)
      (JNIEnv *env, jfloatArray array, jsize start, jsize len, const jfloat *buf);
    void (__stdcall *SetDoubleArrayRegion)
      (JNIEnv *env, jdoubleArray array, jsize start, jsize len, const jdouble *buf);

    jint (__stdcall *RegisterNatives)
      (JNIEnv *env, jclass clazz, const JNINativeMethod *methods,
       jint nMethods);
    jint (__stdcall *UnregisterNatives)
      (JNIEnv *env, jclass clazz);

    jint (__stdcall *MonitorEnter)
      (JNIEnv *env, jobject obj);
    jint (__stdcall *MonitorExit)
      (JNIEnv *env, jobject obj);

    jint (__stdcall *GetJavaVM)
      (JNIEnv *env, JavaVM **vm);

    void (__stdcall *GetStringRegion)
      (JNIEnv *env, jstring str, jsize start, jsize len, jchar *buf);
    void (__stdcall *GetStringUTFRegion)
      (JNIEnv *env, jstring str, jsize start, jsize len, char *buf);

    void * (__stdcall *GetPrimitiveArrayCritical)
      (JNIEnv *env, jarray array, jboolean *isCopy);
    void (__stdcall *ReleasePrimitiveArrayCritical)
      (JNIEnv *env, jarray array, void *carray, jint mode);

    const jchar * (__stdcall *GetStringCritical)
      (JNIEnv *env, jstring string, jboolean *isCopy);
    void (__stdcall *ReleaseStringCritical)
      (JNIEnv *env, jstring string, const jchar *cstring);

    jweak (__stdcall *NewWeakGlobalRef)
       (JNIEnv *env, jobject obj);
    void (__stdcall *DeleteWeakGlobalRef)
       (JNIEnv *env, jweak ref);

    jboolean (__stdcall *ExceptionCheck)
       (JNIEnv *env);

    jobject (__stdcall *NewDirectByteBuffer)
       (JNIEnv* env, void* address, jlong capacity);
    void* (__stdcall *GetDirectBufferAddress)
       (JNIEnv* env, jobject buf);
    jlong (__stdcall *GetDirectBufferCapacity)
       (JNIEnv* env, jobject buf);



    jobjectRefType (__stdcall *GetObjectRefType)
        (JNIEnv* env, jobject obj);
};
struct JNIEnv_ {
    const struct JNINativeInterface_ *functions;
};

typedef struct JavaVMOption {
    char *optionString;
    void *extraInfo;
} JavaVMOption;

typedef struct JavaVMInitArgs {
    jint version;

    jint nOptions;
    JavaVMOption *options;
    jboolean ignoreUnrecognized;
} JavaVMInitArgs;

typedef struct JavaVMAttachArgs {
    jint version;

    char *name;
    jobject group;
} JavaVMAttachArgs;
struct JNIInvokeInterface_ {
    void *reserved0;
    void *reserved1;
    void *reserved2;

    jint (__stdcall *DestroyJavaVM)(JavaVM *vm);

    jint (__stdcall *AttachCurrentThread)(JavaVM *vm, void **penv, void *args);

    jint (__stdcall *DetachCurrentThread)(JavaVM *vm);

    jint (__stdcall *GetEnv)(JavaVM *vm, void **penv, jint version);

    jint (__stdcall *AttachCurrentThreadAsDaemon)(JavaVM *vm, void **penv, void *args);
};

struct JavaVM_ {
    const struct JNIInvokeInterface_ *functions;
};






__declspec(dllimport) jint __stdcall
JNI_GetDefaultJavaVMInitArgs(void *args);

__declspec(dllimport) jint __stdcall
JNI_CreateJavaVM(JavaVM **pvm, void **penv, void *args);

__declspec(dllimport) jint __stdcall
JNI_GetCreatedJavaVMs(JavaVM **, jsize, jsize *);


__declspec(dllexport) jint __stdcall
JNI_OnLoad(JavaVM *vm, void *reserved);

__declspec(dllexport) void __stdcall
JNI_OnUnload(JavaVM *vm, void *reserved);
typedef long jint;
typedef __int64 jlong;
typedef signed char jbyte;
typedef unsigned char jboolean;
typedef unsigned short jchar;
typedef short jshort;
typedef float jfloat;
typedef double jdouble;

typedef jint jsize;
struct _jobject;

typedef struct _jobject *jobject;
typedef jobject jclass;
typedef jobject jthrowable;
typedef jobject jstring;
typedef jobject jarray;
typedef jarray jbooleanArray;
typedef jarray jbyteArray;
typedef jarray jcharArray;
typedef jarray jshortArray;
typedef jarray jintArray;
typedef jarray jlongArray;
typedef jarray jfloatArray;
typedef jarray jdoubleArray;
typedef jarray jobjectArray;



typedef jobject jweak;

typedef union jvalue {
    jboolean z;
    jbyte b;
    jchar c;
    jshort s;
    jint i;
    jlong j;
    jfloat f;
    jdouble d;
    jobject l;
} jvalue;

struct _jfieldID;
typedef struct _jfieldID *jfieldID;

struct _jmethodID;
typedef struct _jmethodID *jmethodID;


typedef enum _jobjectType {
     JNIInvalidRefType = 0,
     JNILocalRefType = 1,
     JNIGlobalRefType = 2,
     JNIWeakGlobalRefType = 3
} jobjectRefType;
typedef struct {
    char *name;
    char *signature;
    void *fnPtr;
} JNINativeMethod;





struct JNINativeInterface_;

struct JNIEnv_;




typedef const struct JNINativeInterface_ *JNIEnv;






struct JNIInvokeInterface_;

struct JavaVM_;




typedef const struct JNIInvokeInterface_ *JavaVM;


struct JNINativeInterface_ {
    void *reserved0;
    void *reserved1;
    void *reserved2;

    void *reserved3;
    jint (__stdcall *GetVersion)(JNIEnv *env);

    jclass (__stdcall *DefineClass)
      (JNIEnv *env, const char *name, jobject loader, const jbyte *buf,
       jsize len);
    jclass (__stdcall *FindClass)
      (JNIEnv *env, const char *name);

    jmethodID (__stdcall *FromReflectedMethod)
      (JNIEnv *env, jobject method);
    jfieldID (__stdcall *FromReflectedField)
      (JNIEnv *env, jobject field);

    jobject (__stdcall *ToReflectedMethod)
      (JNIEnv *env, jclass cls, jmethodID methodID, jboolean isStatic);

    jclass (__stdcall *GetSuperclass)
      (JNIEnv *env, jclass sub);
    jboolean (__stdcall *IsAssignableFrom)
      (JNIEnv *env, jclass sub, jclass sup);

    jobject (__stdcall *ToReflectedField)
      (JNIEnv *env, jclass cls, jfieldID fieldID, jboolean isStatic);

    jint (__stdcall *Throw)
      (JNIEnv *env, jthrowable obj);
    jint (__stdcall *ThrowNew)
      (JNIEnv *env, jclass clazz, const char *msg);
    jthrowable (__stdcall *ExceptionOccurred)
      (JNIEnv *env);
    void (__stdcall *ExceptionDescribe)
      (JNIEnv *env);
    void (__stdcall *ExceptionClear)
      (JNIEnv *env);
    void (__stdcall *FatalError)
      (JNIEnv *env, const char *msg);

    jint (__stdcall *PushLocalFrame)
      (JNIEnv *env, jint capacity);
    jobject (__stdcall *PopLocalFrame)
      (JNIEnv *env, jobject result);

    jobject (__stdcall *NewGlobalRef)
      (JNIEnv *env, jobject lobj);
    void (__stdcall *DeleteGlobalRef)
      (JNIEnv *env, jobject gref);
    void (__stdcall *DeleteLocalRef)
      (JNIEnv *env, jobject obj);
    jboolean (__stdcall *IsSameObject)
      (JNIEnv *env, jobject obj1, jobject obj2);
    jobject (__stdcall *NewLocalRef)
      (JNIEnv *env, jobject ref);
    jint (__stdcall *EnsureLocalCapacity)
      (JNIEnv *env, jint capacity);

    jobject (__stdcall *AllocObject)
      (JNIEnv *env, jclass clazz);
    jobject (__stdcall *NewObject)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jobject (__stdcall *NewObjectV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jobject (__stdcall *NewObjectA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jclass (__stdcall *GetObjectClass)
      (JNIEnv *env, jobject obj);
    jboolean (__stdcall *IsInstanceOf)
      (JNIEnv *env, jobject obj, jclass clazz);

    jmethodID (__stdcall *GetMethodID)
      (JNIEnv *env, jclass clazz, const char *name, const char *sig);

    jobject (__stdcall *CallObjectMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jobject (__stdcall *CallObjectMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jobject (__stdcall *CallObjectMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue * args);

    jboolean (__stdcall *CallBooleanMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jboolean (__stdcall *CallBooleanMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jboolean (__stdcall *CallBooleanMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue * args);

    jbyte (__stdcall *CallByteMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jbyte (__stdcall *CallByteMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jbyte (__stdcall *CallByteMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    jchar (__stdcall *CallCharMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jchar (__stdcall *CallCharMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jchar (__stdcall *CallCharMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    jshort (__stdcall *CallShortMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jshort (__stdcall *CallShortMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jshort (__stdcall *CallShortMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    jint (__stdcall *CallIntMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jint (__stdcall *CallIntMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jint (__stdcall *CallIntMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    jlong (__stdcall *CallLongMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jlong (__stdcall *CallLongMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jlong (__stdcall *CallLongMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    jfloat (__stdcall *CallFloatMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jfloat (__stdcall *CallFloatMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jfloat (__stdcall *CallFloatMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    jdouble (__stdcall *CallDoubleMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    jdouble (__stdcall *CallDoubleMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    jdouble (__stdcall *CallDoubleMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);

    void (__stdcall *CallVoidMethod)
      (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    void (__stdcall *CallVoidMethodV)
      (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
    void (__stdcall *CallVoidMethodA)
      (JNIEnv *env, jobject obj, jmethodID methodID, const jvalue * args);

    jobject (__stdcall *CallNonvirtualObjectMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jobject (__stdcall *CallNonvirtualObjectMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jobject (__stdcall *CallNonvirtualObjectMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue * args);

    jboolean (__stdcall *CallNonvirtualBooleanMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jboolean (__stdcall *CallNonvirtualBooleanMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jboolean (__stdcall *CallNonvirtualBooleanMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue * args);

    jbyte (__stdcall *CallNonvirtualByteMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jbyte (__stdcall *CallNonvirtualByteMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jbyte (__stdcall *CallNonvirtualByteMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    jchar (__stdcall *CallNonvirtualCharMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jchar (__stdcall *CallNonvirtualCharMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jchar (__stdcall *CallNonvirtualCharMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    jshort (__stdcall *CallNonvirtualShortMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jshort (__stdcall *CallNonvirtualShortMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jshort (__stdcall *CallNonvirtualShortMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    jint (__stdcall *CallNonvirtualIntMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jint (__stdcall *CallNonvirtualIntMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jint (__stdcall *CallNonvirtualIntMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    jlong (__stdcall *CallNonvirtualLongMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jlong (__stdcall *CallNonvirtualLongMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jlong (__stdcall *CallNonvirtualLongMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    jfloat (__stdcall *CallNonvirtualFloatMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jfloat (__stdcall *CallNonvirtualFloatMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jfloat (__stdcall *CallNonvirtualFloatMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    jdouble (__stdcall *CallNonvirtualDoubleMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    jdouble (__stdcall *CallNonvirtualDoubleMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    jdouble (__stdcall *CallNonvirtualDoubleMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue *args);

    void (__stdcall *CallNonvirtualVoidMethod)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);
    void (__stdcall *CallNonvirtualVoidMethodV)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       va_list args);
    void (__stdcall *CallNonvirtualVoidMethodA)
      (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID,
       const jvalue * args);

    jfieldID (__stdcall *GetFieldID)
      (JNIEnv *env, jclass clazz, const char *name, const char *sig);

    jobject (__stdcall *GetObjectField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jboolean (__stdcall *GetBooleanField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jbyte (__stdcall *GetByteField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jchar (__stdcall *GetCharField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jshort (__stdcall *GetShortField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jint (__stdcall *GetIntField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jlong (__stdcall *GetLongField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jfloat (__stdcall *GetFloatField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);
    jdouble (__stdcall *GetDoubleField)
      (JNIEnv *env, jobject obj, jfieldID fieldID);

    void (__stdcall *SetObjectField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jobject val);
    void (__stdcall *SetBooleanField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jboolean val);
    void (__stdcall *SetByteField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jbyte val);
    void (__stdcall *SetCharField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jchar val);
    void (__stdcall *SetShortField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jshort val);
    void (__stdcall *SetIntField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jint val);
    void (__stdcall *SetLongField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jlong val);
    void (__stdcall *SetFloatField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jfloat val);
    void (__stdcall *SetDoubleField)
      (JNIEnv *env, jobject obj, jfieldID fieldID, jdouble val);

    jmethodID (__stdcall *GetStaticMethodID)
      (JNIEnv *env, jclass clazz, const char *name, const char *sig);

    jobject (__stdcall *CallStaticObjectMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jobject (__stdcall *CallStaticObjectMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jobject (__stdcall *CallStaticObjectMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jboolean (__stdcall *CallStaticBooleanMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jboolean (__stdcall *CallStaticBooleanMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jboolean (__stdcall *CallStaticBooleanMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jbyte (__stdcall *CallStaticByteMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jbyte (__stdcall *CallStaticByteMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jbyte (__stdcall *CallStaticByteMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jchar (__stdcall *CallStaticCharMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jchar (__stdcall *CallStaticCharMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jchar (__stdcall *CallStaticCharMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jshort (__stdcall *CallStaticShortMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jshort (__stdcall *CallStaticShortMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jshort (__stdcall *CallStaticShortMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jint (__stdcall *CallStaticIntMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jint (__stdcall *CallStaticIntMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jint (__stdcall *CallStaticIntMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jlong (__stdcall *CallStaticLongMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jlong (__stdcall *CallStaticLongMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jlong (__stdcall *CallStaticLongMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jfloat (__stdcall *CallStaticFloatMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jfloat (__stdcall *CallStaticFloatMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jfloat (__stdcall *CallStaticFloatMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    jdouble (__stdcall *CallStaticDoubleMethod)
      (JNIEnv *env, jclass clazz, jmethodID methodID, ...);
    jdouble (__stdcall *CallStaticDoubleMethodV)
      (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);
    jdouble (__stdcall *CallStaticDoubleMethodA)
      (JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);

    void (__stdcall *CallStaticVoidMethod)
      (JNIEnv *env, jclass cls, jmethodID methodID, ...);
    void (__stdcall *CallStaticVoidMethodV)
      (JNIEnv *env, jclass cls, jmethodID methodID, va_list args);
    void (__stdcall *CallStaticVoidMethodA)
      (JNIEnv *env, jclass cls, jmethodID methodID, const jvalue * args);

    jfieldID (__stdcall *GetStaticFieldID)
      (JNIEnv *env, jclass clazz, const char *name, const char *sig);
    jobject (__stdcall *GetStaticObjectField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jboolean (__stdcall *GetStaticBooleanField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jbyte (__stdcall *GetStaticByteField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jchar (__stdcall *GetStaticCharField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jshort (__stdcall *GetStaticShortField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jint (__stdcall *GetStaticIntField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jlong (__stdcall *GetStaticLongField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jfloat (__stdcall *GetStaticFloatField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);
    jdouble (__stdcall *GetStaticDoubleField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID);

    void (__stdcall *SetStaticObjectField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jobject value);
    void (__stdcall *SetStaticBooleanField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jboolean value);
    void (__stdcall *SetStaticByteField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jbyte value);
    void (__stdcall *SetStaticCharField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jchar value);
    void (__stdcall *SetStaticShortField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jshort value);
    void (__stdcall *SetStaticIntField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jint value);
    void (__stdcall *SetStaticLongField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jlong value);
    void (__stdcall *SetStaticFloatField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jfloat value);
    void (__stdcall *SetStaticDoubleField)
      (JNIEnv *env, jclass clazz, jfieldID fieldID, jdouble value);

    jstring (__stdcall *NewString)
      (JNIEnv *env, const jchar *unicode, jsize len);
    jsize (__stdcall *GetStringLength)
      (JNIEnv *env, jstring str);
    const jchar *(__stdcall *GetStringChars)
      (JNIEnv *env, jstring str, jboolean *isCopy);
    void (__stdcall *ReleaseStringChars)
      (JNIEnv *env, jstring str, const jchar *chars);

    jstring (__stdcall *NewStringUTF)
      (JNIEnv *env, const char *utf);
    jsize (__stdcall *GetStringUTFLength)
      (JNIEnv *env, jstring str);
    const char* (__stdcall *GetStringUTFChars)
      (JNIEnv *env, jstring str, jboolean *isCopy);
    void (__stdcall *ReleaseStringUTFChars)
      (JNIEnv *env, jstring str, const char* chars);


    jsize (__stdcall *GetArrayLength)
      (JNIEnv *env, jarray array);

    jobjectArray (__stdcall *NewObjectArray)
      (JNIEnv *env, jsize len, jclass clazz, jobject init);
    jobject (__stdcall *GetObjectArrayElement)
      (JNIEnv *env, jobjectArray array, jsize index);
    void (__stdcall *SetObjectArrayElement)
      (JNIEnv *env, jobjectArray array, jsize index, jobject val);

    jbooleanArray (__stdcall *NewBooleanArray)
      (JNIEnv *env, jsize len);
    jbyteArray (__stdcall *NewByteArray)
      (JNIEnv *env, jsize len);
    jcharArray (__stdcall *NewCharArray)
      (JNIEnv *env, jsize len);
    jshortArray (__stdcall *NewShortArray)
      (JNIEnv *env, jsize len);
    jintArray (__stdcall *NewIntArray)
      (JNIEnv *env, jsize len);
    jlongArray (__stdcall *NewLongArray)
      (JNIEnv *env, jsize len);
    jfloatArray (__stdcall *NewFloatArray)
      (JNIEnv *env, jsize len);
    jdoubleArray (__stdcall *NewDoubleArray)
      (JNIEnv *env, jsize len);

    jboolean * (__stdcall *GetBooleanArrayElements)
      (JNIEnv *env, jbooleanArray array, jboolean *isCopy);
    jbyte * (__stdcall *GetByteArrayElements)
      (JNIEnv *env, jbyteArray array, jboolean *isCopy);
    jchar * (__stdcall *GetCharArrayElements)
      (JNIEnv *env, jcharArray array, jboolean *isCopy);
    jshort * (__stdcall *GetShortArrayElements)
      (JNIEnv *env, jshortArray array, jboolean *isCopy);
    jint * (__stdcall *GetIntArrayElements)
      (JNIEnv *env, jintArray array, jboolean *isCopy);
    jlong * (__stdcall *GetLongArrayElements)
      (JNIEnv *env, jlongArray array, jboolean *isCopy);
    jfloat * (__stdcall *GetFloatArrayElements)
      (JNIEnv *env, jfloatArray array, jboolean *isCopy);
    jdouble * (__stdcall *GetDoubleArrayElements)
      (JNIEnv *env, jdoubleArray array, jboolean *isCopy);

    void (__stdcall *ReleaseBooleanArrayElements)
      (JNIEnv *env, jbooleanArray array, jboolean *elems, jint mode);
    void (__stdcall *ReleaseByteArrayElements)
      (JNIEnv *env, jbyteArray array, jbyte *elems, jint mode);
    void (__stdcall *ReleaseCharArrayElements)
      (JNIEnv *env, jcharArray array, jchar *elems, jint mode);
    void (__stdcall *ReleaseShortArrayElements)
      (JNIEnv *env, jshortArray array, jshort *elems, jint mode);
    void (__stdcall *ReleaseIntArrayElements)
      (JNIEnv *env, jintArray array, jint *elems, jint mode);
    void (__stdcall *ReleaseLongArrayElements)
      (JNIEnv *env, jlongArray array, jlong *elems, jint mode);
    void (__stdcall *ReleaseFloatArrayElements)
      (JNIEnv *env, jfloatArray array, jfloat *elems, jint mode);
    void (__stdcall *ReleaseDoubleArrayElements)
      (JNIEnv *env, jdoubleArray array, jdouble *elems, jint mode);

    void (__stdcall *GetBooleanArrayRegion)
      (JNIEnv *env, jbooleanArray array, jsize start, jsize l, jboolean *buf);
    void (__stdcall *GetByteArrayRegion)
      (JNIEnv *env, jbyteArray array, jsize start, jsize len, jbyte *buf);
    void (__stdcall *GetCharArrayRegion)
      (JNIEnv *env, jcharArray array, jsize start, jsize len, jchar *buf);
    void (__stdcall *GetShortArrayRegion)
      (JNIEnv *env, jshortArray array, jsize start, jsize len, jshort *buf);
    void (__stdcall *GetIntArrayRegion)
      (JNIEnv *env, jintArray array, jsize start, jsize len, jint *buf);
    void (__stdcall *GetLongArrayRegion)
      (JNIEnv *env, jlongArray array, jsize start, jsize len, jlong *buf);
    void (__stdcall *GetFloatArrayRegion)
      (JNIEnv *env, jfloatArray array, jsize start, jsize len, jfloat *buf);
    void (__stdcall *GetDoubleArrayRegion)
      (JNIEnv *env, jdoubleArray array, jsize start, jsize len, jdouble *buf);

    void (__stdcall *SetBooleanArrayRegion)
      (JNIEnv *env, jbooleanArray array, jsize start, jsize l, const jboolean *buf);
    void (__stdcall *SetByteArrayRegion)
      (JNIEnv *env, jbyteArray array, jsize start, jsize len, const jbyte *buf);
    void (__stdcall *SetCharArrayRegion)
      (JNIEnv *env, jcharArray array, jsize start, jsize len, const jchar *buf);
    void (__stdcall *SetShortArrayRegion)
      (JNIEnv *env, jshortArray array, jsize start, jsize len, const jshort *buf);
    void (__stdcall *SetIntArrayRegion)
      (JNIEnv *env, jintArray array, jsize start, jsize len, const jint *buf);
    void (__stdcall *SetLongArrayRegion)
      (JNIEnv *env, jlongArray array, jsize start, jsize len, const jlong *buf);
    void (__stdcall *SetFloatArrayRegion)
      (JNIEnv *env, jfloatArray array, jsize start, jsize len, const jfloat *buf);
    void (__stdcall *SetDoubleArrayRegion)
      (JNIEnv *env, jdoubleArray array, jsize start, jsize len, const jdouble *buf);

    jint (__stdcall *RegisterNatives)
      (JNIEnv *env, jclass clazz, const JNINativeMethod *methods,
       jint nMethods);
    jint (__stdcall *UnregisterNatives)
      (JNIEnv *env, jclass clazz);

    jint (__stdcall *MonitorEnter)
      (JNIEnv *env, jobject obj);
    jint (__stdcall *MonitorExit)
      (JNIEnv *env, jobject obj);

    jint (__stdcall *GetJavaVM)
      (JNIEnv *env, JavaVM **vm);

    void (__stdcall *GetStringRegion)
      (JNIEnv *env, jstring str, jsize start, jsize len, jchar *buf);
    void (__stdcall *GetStringUTFRegion)
      (JNIEnv *env, jstring str, jsize start, jsize len, char *buf);

    void * (__stdcall *GetPrimitiveArrayCritical)
      (JNIEnv *env, jarray array, jboolean *isCopy);
    void (__stdcall *ReleasePrimitiveArrayCritical)
      (JNIEnv *env, jarray array, void *carray, jint mode);

    const jchar * (__stdcall *GetStringCritical)
      (JNIEnv *env, jstring string, jboolean *isCopy);
    void (__stdcall *ReleaseStringCritical)
      (JNIEnv *env, jstring string, const jchar *cstring);

    jweak (__stdcall *NewWeakGlobalRef)
       (JNIEnv *env, jobject obj);
    void (__stdcall *DeleteWeakGlobalRef)
       (JNIEnv *env, jweak ref);

    jboolean (__stdcall *ExceptionCheck)
       (JNIEnv *env);

    jobject (__stdcall *NewDirectByteBuffer)
       (JNIEnv* env, void* address, jlong capacity);
    void* (__stdcall *GetDirectBufferAddress)
       (JNIEnv* env, jobject buf);
    jlong (__stdcall *GetDirectBufferCapacity)
       (JNIEnv* env, jobject buf);



    jobjectRefType (__stdcall *GetObjectRefType)
        (JNIEnv* env, jobject obj);
};
struct JNIEnv_ {
    const struct JNINativeInterface_ *functions;
};

typedef struct JavaVMOption {
    char *optionString;
    void *extraInfo;
} JavaVMOption;

typedef struct JavaVMInitArgs {
    jint version;

    jint nOptions;
    JavaVMOption *options;
    jboolean ignoreUnrecognized;
} JavaVMInitArgs;

typedef struct JavaVMAttachArgs {
    jint version;

    char *name;
    jobject group;
} JavaVMAttachArgs;
struct JNIInvokeInterface_ {
    void *reserved0;
    void *reserved1;
    void *reserved2;

    jint (__stdcall *DestroyJavaVM)(JavaVM *vm);

    jint (__stdcall *AttachCurrentThread)(JavaVM *vm, void **penv, void *args);

    jint (__stdcall *DetachCurrentThread)(JavaVM *vm);

    jint (__stdcall *GetEnv)(JavaVM *vm, void **penv, jint version);

    jint (__stdcall *AttachCurrentThreadAsDaemon)(JavaVM *vm, void **penv, void *args);
};

struct JavaVM_ {
    const struct JNIInvokeInterface_ *functions;
};






__declspec(dllimport) jint __stdcall
JNI_GetDefaultJavaVMInitArgs(void *args);

__declspec(dllimport) jint __stdcall
JNI_CreateJavaVM(JavaVM **pvm, void **penv, void *args);

__declspec(dllimport) jint __stdcall
JNI_GetCreatedJavaVMs(JavaVM **, jsize, jsize *);


__declspec(dllexport) jint __stdcall
JNI_OnLoad(JavaVM *vm, void *reserved);

__declspec(dllexport) void __stdcall
JNI_OnUnload(JavaVM *vm, void *reserved);
