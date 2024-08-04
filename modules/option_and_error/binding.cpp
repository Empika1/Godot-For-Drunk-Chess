#include "binding.h"

#define STR(x) #x

#define OPTION_CLASS_DEFINITION(TUpper, T)\
void Option ## TUpper::_bind_methods() {\
    ClassDB::bind_method(D_METHOD("has_value"), &Option ## TUpper::has_value);\
    ClassDB::bind_method(D_METHOD("get_value", "default_"), &Option ## TUpper::get_value);\
    ClassDB::bind_method(D_METHOD("set_value", "value"), &Option ## TUpper::set_value);\
    ClassDB::bind_method(D_METHOD("empty_value"), &Option ## TUpper::empty_value);\
    ClassDB::bind_static_method(STR(Option ## TUpper), D_METHOD("new_value", "value"), &Option ## TUpper::new_value);\
    ClassDB::bind_static_method(STR(Option ## TUpper), D_METHOD("new_empty"), &Option ## TUpper::new_empty);\
}\
Option ## TUpper::Option ## TUpper(T value) : o(value) {}\
Option ## TUpper::Option ## TUpper() : o() {}\
\
constexpr bool Option ## TUpper::has_value() const {\
    return o.has();\
}\
\
constexpr T Option ## TUpper::get_value(T default_) const {\
    return o.get(default_);\
}\
\
constexpr void Option ## TUpper::set_value(T value) {\
    o.set(value);\
}\
\
constexpr void Option ## TUpper::empty_value() {\
    o.empty();\
}\
\
Ref<Option ## TUpper> Option ## TUpper::new_value(T value) {\
    Option ## TUpper* o = new Option ## TUpper(value);\
    return Ref<Option ## TUpper>();\
}\
Ref<Option ## TUpper> Option ## TUpper::new_empty() {\
    Option ## TUpper* o = new Option ## TUpper();\
    return Ref<Option ## TUpper>();\
}\

void OptionInt::_bind_methods() { 
    ClassDB::bind_method("has_value", &OptionInt::has_value); 
    ClassDB::bind_method("get_value", &OptionInt::get_value); 
    ClassDB::bind_method("set_value", &OptionInt::set_value); 
    ClassDB::bind_method("empty_value", &OptionInt::empty_value); 
    ClassDB::bind_static_method("OptionInt", "new_value", &OptionInt::new_value); 
    ClassDB::bind_static_method("OptionInt", "new_empty", &OptionInt::new_empty);
}

OptionInt::OptionInt(int value) : o(value) {}
OptionInt::OptionInt() : o() {}

constexpr bool OptionInt::has_value() const { 
    return o.has();
}

constexpr int OptionInt::get_value(int default_) const { 
    return o.get(default_);
}

constexpr void OptionInt::set_value(int value) { 
    o.set(value);
}

constexpr void OptionInt::empty_value() { 
    o.empty();
}

Ref<OptionInt> OptionInt::new_value(int value) { 
    Ref<OptionInt> r;
    r.instantiate();
    r->set_value(value);
    return r;
}

Ref<OptionInt> OptionInt::new_empty() { 
    Ref<OptionInt> r;
    r.instantiate();
    r->empty_value();
    return r;
}

#undef STR
#undef OPTION_CLASS_DEFINITION