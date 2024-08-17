#include <string>
#include "pointBinding.h"
#include "returnRef.h"

namespace DCM = DrunkChessMath;

void Point::_bind_methods() {
    ClassDB::bind_method(D_METHOD("getX"), &Point::getX);
    ClassDB::bind_method(D_METHOD("getY"), &Point::getY);
    ClassDB::bind_method(D_METHOD("add", "other"), &Point::add);
    ClassDB::bind_method(D_METHOD("subtract", "other"), &Point::subtract);
    ClassDB::bind_method(D_METHOD("dot", "other"), &Point::dot);
    ClassDB::bind_method(D_METHOD("cross", "other"), &Point::cross);
    ClassDB::bind_method(D_METHOD("lengthSquared"), &Point::lengthSquared);
    ClassDB::bind_method(D_METHOD("distanceSquared", "other"), &Point::distanceSquared);
    ClassDB::bind_method(D_METHOD("arePointingInSameDirection", "other"), &Point::arePointingInSameDirection);
    ClassDB::bind_method(D_METHOD("areCollinear", "other1", "other2", "other3"), &Point::areCollinear);
    ClassDB::bind_method(D_METHOD("toString"), &Point::toString);
    ClassDB::bind_static_method("Point", D_METHOD("newPoint", "x", "y"), &Point::newPoint);

    ADD_PROPERTY(PropertyInfo(Variant::INT, "x"), "", "getX");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "y"), "", "getY");
}

DCM::intD Point::getX() const {
    return p.x;
}

DCM::intD Point::getY() const {
    return p.y;
}

Ref<Point> Point::add(Ref<Point> const other) const {
    RETURN_REF(Point, p, p + other->p)
}

Ref<Point> Point::subtract(Ref<Point> const other) const {
    RETURN_REF(Point, p, p - other->p)
}

DCM::intD Point::dot(Ref<Point> const other) const {
    return p * other->p;
}

DCM::intD Point::cross(Ref<Point> const other) const {
    return p / other->p;
}

bool Point::equals(Ref<Point> const other) const {
    return p == other->p;
}

DCM::uintD Point::lengthSquared() const {
    return DCM::lengthSquared(p);
}

DCM::uintD Point::distanceSquared(Ref<Point> const other) const {
    return DCM::distanceSquared(p, other->p);
}

bool Point::arePointingInSameDirection(Ref<Point> const other) const {
    return DCM::arePointingInSameDirection(p, other->p);
}

bool Point::areCollinear(Ref<Point> const other1, Ref<Point> const other2, Ref<Point> const other3) const {
    return DCM::areCollinear(p, other1->p, other2->p, other3->p);
}

String Point::toString() const {
    return String{DCM::toString(p).c_str()};
}

Ref<Point> Point::newPoint(DCM::intD const x, DCM::intD const y) {
    RETURN_REF(Point, p, (DCM::Point{x, y}))
}

Point::Point() : p{0, 0} {}