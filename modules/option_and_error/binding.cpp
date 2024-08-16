#include "binding.h"

#define STR(x) #x

#define OPTION_CLASS_DEFINITION(TUpper, T)\
void Option ## TUpper::_bind_methods() {\
    ClassDB::bind_method(D_METHOD("hasValue"), &Option ## TUpper::hasValue);\
    ClassDB::bind_method(D_METHOD("getValue", "default_"), &Option ## TUpper::getValue);\
    ClassDB::bind_method(D_METHOD("setValue", "value"), &Option ## TUpper::setValue);\
    ClassDB::bind_method(D_METHOD("emptyValue"), &Option ## TUpper::emptyValue);\
    ClassDB::bind_static_method(STR(Option ## TUpper), D_METHOD("newValue", "value"), &Option ## TUpper::newValue);\
    ClassDB::bind_static_method(STR(Option ## TUpper), D_METHOD("newEmpty"), &Option ## TUpper::newEmpty);\
}\
Option ## TUpper::Option ## TUpper(T value) : o{value} {}\
Option ## TUpper::Option ## TUpper() : o{} {}\
\
bool Option ## TUpper::hasValue() const {\
    return o.has();\
}\
\
T Option ## TUpper::getValue(T default_) const {\
    return o.get(default_);\
}\
\
void Option ## TUpper::setValue(T value) {\
    o.set(value);\
}\
\
void Option ## TUpper::emptyValue() {\
    o.empty();\
}\
\
Ref<Option ## TUpper> Option ## TUpper::newValue(T value) {\
    Ref<Option ## TUpper> r;\
    r.instantiate();\
    new(r.ptr()) Option ## TUpper{value};\
    return r;\
}\
Ref<Option ## TUpper> Option ## TUpper::newEmpty() {\
    Ref<Option ## TUpper> r;\
    r.instantiate();\
    new(r.ptr()) Option ## TUpper{};\
    return r;\
}\

OPTION_CLASS_DEFINITION(Int, int)
OPTION_CLASS_DEFINITION(RefCounted, Ref<RefCounted>)

#undef OPTION_CLASS_DEFINITION

#define ERRORABLE_CLASS_DEFINITION(TUpper, T)\
void Errorable ## TUpper::_bind_methods() {\
    ClassDB::bind_method(D_METHOD("hasValue"), &Errorable ## TUpper::hasValue);\
    ClassDB::bind_method(D_METHOD("getValue", "default_"), &Errorable ## TUpper::getValue);\
    ClassDB::bind_method(D_METHOD("getErrorCode", "default_"), &Errorable ## TUpper::getErrorCode);\
    ClassDB::bind_method(D_METHOD("getErrorMessage", "default_"), &Errorable ## TUpper::getErrorMessage);\
    ClassDB::bind_method(D_METHOD("setValue", "value"), &Errorable ## TUpper::setValue);\
    ClassDB::bind_method(D_METHOD("setError", "errorCode", "errorMessage"), &Errorable ## TUpper::setError);\
    ClassDB::bind_static_method(STR(Errorable ## TUpper), D_METHOD("newValue", "value"), &Errorable ## TUpper::newValue);\
    ClassDB::bind_static_method(STR(Errorable ## TUpper), D_METHOD("newError", "errorCode", "errorMessage"), &Errorable ## TUpper::newError);\
}\
\
Errorable ## TUpper::Errorable ## TUpper(T value) : e{value} {}\
Errorable ## TUpper::Errorable ## TUpper(DCError::Error error, String errorMessage) : e{error, errorMessage} {}\
Errorable ## TUpper::Errorable ## TUpper() : e{} {}\
\
bool Errorable ## TUpper::hasValue() const {\
    return e.hasValue();\
}\
\
T Errorable ## TUpper::getValue(T default_) const {\
    return e.getValue(default_);\
}\
\
DCError::Error Errorable ## TUpper::getErrorCode(DCError::Error default_) const {\
    return e.getErrorCode(default_);\
}\
\
String Errorable ## TUpper::getErrorMessage(String default_) const {\
    return e.getErrorMessage(default_);\
}\
\
void Errorable ## TUpper::setValue(T value) {\
    e.setValue(value);\
}\
\
void Errorable ## TUpper::setError(DCError::Error errorCode, String errorMessage) {\
    e.setError(errorCode, errorMessage);\
}\
\
Ref<Errorable ## TUpper> Errorable ## TUpper::newValue(T value) {\
    Ref<Errorable ## TUpper> r;\
    r.instantiate();\
    new(r.ptr()) Errorable ## TUpper{value};\
    return r;\
}\
\
Ref<Errorable ## TUpper> Errorable ## TUpper::newError(DCError::Error errorCode, String errorMessage) {\
    Ref<Errorable ## TUpper> r;\
    r.instantiate();\
    new(r.ptr()) Errorable ## TUpper{errorCode, errorMessage};\
    return r;\
}\

ERRORABLE_CLASS_DEFINITION(Int, int)

#undef ERRORABLE_CLASS_DEFINITION

#undef STR