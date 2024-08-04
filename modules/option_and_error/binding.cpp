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
    return memnew(Option ## TUpper(value));\
}\
Ref<Option ## TUpper> Option ## TUpper::newEmpty() {\
    Option ## TUpper* o = new Option ## TUpper();\
    return memnew(Option ## TUpper());\
}\

OPTION_CLASS_DEFINITION(Int, int)

#undef OPTION_CLASS_DEFINITION

void ErrorableInt::_bind_methods() {
    ClassDB::bind_method(D_METHOD("hasValue"), &ErrorableInt::hasValue);
    ClassDB::bind_method(D_METHOD("getValue", "default_"), &ErrorableInt::getValue);
    ClassDB::bind_method(D_METHOD("getErrorCode", "default_"), &ErrorableInt::getErrorCode);
    ClassDB::bind_method(D_METHOD("getErrorMessage", "default_"), &ErrorableInt::getErrorMessage);
    ClassDB::bind_method(D_METHOD("setValue", "value"), &ErrorableInt::setValue);
    ClassDB::bind_method(D_METHOD("setError", "errorCode", "errorMessage"), &ErrorableInt::setError);
    ClassDB::bind_static_method("ErrorableInt", D_METHOD("newValue", "value"), &ErrorableInt::newValue);
    ClassDB::bind_static_method("ErrorableInt", D_METHOD("newError", "errorCode", "errorMessage"), &ErrorableInt::newError);
}

ErrorableInt::ErrorableInt(int value) : e{value} {}
ErrorableInt::ErrorableInt(DCError::Error error, String errorMessage) : e{error, errorMessage} {}
ErrorableInt::ErrorableInt() : e{} {}

bool ErrorableInt::hasValue() const {
    return e.hasValue();
}

int ErrorableInt::getValue(int default_) const {
    return e.getValue(default_);
}

DCError::Error ErrorableInt::getErrorCode(DCError::Error default_) const {
    return e.getErrorCode(default_);
}

String ErrorableInt::getErrorMessage(String default_) const {
    return e.getErrorMessage(default_);
}

void ErrorableInt::setValue(int value) {
    e.setValue(value);
}

void ErrorableInt::setError(DCError::Error errorCode, String errorMessage) {
    e.setError(errorCode, errorMessage);
}

Ref<ErrorableInt> ErrorableInt::newValue(int value) {
    return memnew(ErrorableInt(value));
}

Ref<ErrorableInt> ErrorableInt::newError(DCError::Error errorCode, String errorMessage) {
    return memnew(ErrorableInt(errorCode, errorMessage));
}

#undef STR