#ifndef OPTION_AND_ERROR_BINDING_H
#define OPTION_AND_ERROR_BINDING_H

#include "core/object/ref_counted.h"
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
    /*refcounted constructor isnt constexpr :(*/\
    Option ## TUpper(T value);\
    Option ## TUpper();\
\
protected:\
    static void _bind_methods();\
public:\
    constexpr bool has_value() const;\
\
/*returns value if has, else default*/\
    constexpr T get_value(T default_) const;\
\
    constexpr void set_value(T value);\
\
    constexpr void empty_value();\
\
    static Ref<Option ## TUpper> new_value(T value);\
    static Ref<Option ## TUpper> new_empty();\
};

class OptionInt : public RefCounted { 
    GDCLASS(OptionInt, RefCounted)

    Option<int> o; 

protected: 
    static void _bind_methods();

public: 
    constexpr bool has_value() const; 
    constexpr int get_value(int default_) const; 
    constexpr void set_value(int value); 
    constexpr void empty_value(); 
    static Ref<OptionInt> new_value(int value); 
    static Ref<OptionInt> new_empty();

    OptionInt(int value); 
    OptionInt();
};

#undef OPTION_CLASS_DECLARATION

#endif