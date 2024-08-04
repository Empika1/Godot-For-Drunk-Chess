/* summator.cpp */

#include "binding.h"

void Point::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_thinga", "thinga_"), &Point::set_thinga);
    ClassDB::bind_method(D_METHOD("get_thinga"), &Point::get_thinga);

    ClassDB::bind_method(D_METHOD("set_thingb", "thingb_"), &Point::set_thingb);
    ClassDB::bind_method(D_METHOD("get_thingb"), &Point::get_thingb);

    ADD_PROPERTY(PropertyInfo(Variant::INT, "thinga"), "set_thinga", "get_thinga");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "thingb"), "set_thingb", "get_thingb");
}

Point::Point() {
}

void Point::set_thinga(int thinga_) {
    thinga = thinga_;
}

int Point::get_thinga() {
    return thinga;
}

void Point::set_thingb(float thingb_) {
    thingb = thingb_;
}

float Point::get_thingb() {
    return thingb;
}