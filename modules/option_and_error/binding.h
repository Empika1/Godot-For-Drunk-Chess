#ifndef OPTION_AND_ERROR_BINDING_H
#define OPTION_AND_ERROR_BINDING_H

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "thirdparty/mine/OptionAndError/option.h"
#include "thirdparty/mine/OptionAndError/errorable.h"
#include "modules/drunk_chess_logic/error.h"

//poor man's template, as templates don't play nice with godot bindings
#define OPTION_CLASS_DECLARATION(TUpper, T)\
class Option ## TUpper : public RefCounted {\
    GDCLASS(Option ## TUpper, RefCounted)\
\
    Option<T> o;\
\
protected:\
    static void _bind_methods();\
\
public:\
    bool hasValue() const;\
    /*returns value if has, else default*/\
    T getValue(T default_) const;\
    void setValue(T value);\
    void emptyValue();\
\
    static Ref<Option ## TUpper> newValue(T value);\
    static Ref<Option ## TUpper> newEmpty();\
\
    /*refcounted constructor isnt :(*/\
    Option ## TUpper(T value);\
    Option ## TUpper();\
};

OPTION_CLASS_DECLARATION(Int, int)
OPTION_CLASS_DECLARATION(RefCounted, Ref<RefCounted>)

#undef OPTION_CLASS_DECLARATION

#define ERRORABLE_CLASS_DECLARATION(TUpper, T)\
class Errorable ## TUpper : public RefCounted {\
    GDCLASS(Errorable ## TUpper, RefCounted)\
\
    Errorable<T, DCError::Error, String, DCError::DC_DEFAULT_ERROR> e;\
\
protected:\
    static void _bind_methods();\
\
public:\
    bool hasValue() const;\
    T getValue(T default_) const;\
    DCError::Error getErrorCode(DCError::Error default_) const;\
    String getErrorMessage(String default_) const;\
    void setValue(T value);\
    void setError(DCError::Error errorCode, String errorMessage = "");\
\
    static Ref<Errorable ## TUpper> newValue(T value);\
    static Ref<Errorable ## TUpper> newError(DCError::Error errorCode, String errorMessage = "");\
\
    Errorable ## TUpper(T value);\
    Errorable ## TUpper(DCError::Error error, String errorMessage = "");\
    Errorable ## TUpper();\
};\

ERRORABLE_CLASS_DECLARATION(Int, int)

#undef ERRORABLE_CLASS_DECLARATION

#endif