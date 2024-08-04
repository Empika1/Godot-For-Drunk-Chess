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
    /*refcounted constructor isnt :(*/\
    Option ## TUpper(T value);\
    Option ## TUpper();\
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
};

OPTION_CLASS_DECLARATION(Int, int)

#undef OPTION_CLASS_DECLARATION

class ErrorableInt : public RefCounted {
    GDCLASS(ErrorableInt, RefCounted)

    Errorable<int, DCError::Error, String, DCError::Error::DC_DEFAULT_ERROR> e;

    ErrorableInt(int value);
    ErrorableInt(DCError::Error error, String errorMessage = "");
    ErrorableInt();

protected:
    static void _bind_methods();

public:
    bool hasValue() const;
    int getValue(int default_) const;
    DCError::Error getErrorCode(DCError::Error default_) const;
    String getErrorMessage(String default_) const;
    void setValue(int value);
    void setError(DCError::Error errorCode, String errorMessage = "");

    static Ref<ErrorableInt> newValue(int value);
    static Ref<ErrorableInt> newError(DCError::Error errorCode, String errorMessage = "");
};

#endif