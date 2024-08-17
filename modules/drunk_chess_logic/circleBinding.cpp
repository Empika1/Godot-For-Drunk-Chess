#include <string>
#include "circleBinding.h"
#include "returnRef.h"

void Circle::_bind_methods() {
    ClassDB::bind_method(D_METHOD("getCenter"), &Circle::getCenter);
    ClassDB::bind_method(D_METHOD("getRadius"), &Circle::getRadius);
    ClassDB::bind_method(D_METHOD("toString"), &Circle::toString);
    ClassDB::bind_method(D_METHOD("rasterizationNumber", "p"), &Circle::rasterizationNumber);
    ClassDB::bind_method(D_METHOD("nthPointOnRasterizaton", "n"), &Circle::nthPointOnRasterization);
    ClassDB::bind_method(D_METHOD("isOnRasteriazation", "p"), &Circle::isOnRasterization);
    ClassDB::bind_method(D_METHOD("nextPointOnRasterization", "prev"), &Circle::nextPointOnRasterization);
    ClassDB::bind_method(D_METHOD("previousPointOnRasterization", "next"), &Circle::previousPointOnRasterization);
    ClassDB::bind_static_method("Circle", D_METHOD("newCircle", "center", "radius"), &Circle::newCircle);

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "center"), "", "getCenter");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "radius"), "", "getRadius");
}

Ref<Point> Circle::getCenter() const {
    RETURN_REF(Point, p, c.center)
}

DCM::uintD Circle::getRadius() const {
    return c.radius;
}

String Circle::toString() const {
    return String(DCM::toString(c).c_str());
}

DCM::intD Circle::rasterizationNumber(Ref<Point> const p) const {
    return DCM::rasterizationNumber(c, p->p);
}

Ref<Point> Circle::nthPointOnRasterization(DCM::intD const n) const {
    RETURN_REF(Point, p, DCM::nthPointOnRasterization(c, n))
}

bool Circle::isOnRasterization(Ref<Point> const p) const {
    return DCM::isOnRasterization(c, p->p);
}

Ref<Point> Circle::nextPointOnRasterization(Ref<Point> const prev) const {
    RETURN_REF(Point, p, DCM::nextPointOnRasterization(c, prev->p))
}

Ref<Point> Circle::previousPointOnRasterization(Ref<Point> const next) const {
    RETURN_REF(Point, p, DCM::previousPointOnRasterization(c, next->p))
}

Ref<Circle> Circle::newCircle(Ref<Point> const center, DCM::uintD const radius) {
    RETURN_REF(Circle, c, (DCM::Circle{center->p, radius}))
}

Circle::Circle() : c{DCM::Point{0, 0}, 1} {}

Circle::Circle(Ref<Point> const center, DCM::uintD const radius) : c{center->p, radius} {}

void Arc::_bind_methods() {
    ClassDB::bind_method(D_METHOD("getCenter"), &Arc::getCenter);
    ClassDB::bind_method(D_METHOD("getRadius"), &Arc::getRadius);
    ClassDB::bind_method(D_METHOD("getP1"), &Arc::getP1);
    ClassDB::bind_method(D_METHOD("getP2"), &Arc::getP2);
    ClassDB::bind_method(D_METHOD("toString"), &Arc::toString);
    ClassDB::bind_method(D_METHOD("isInArc_", "signCrossProduct1", "signCrossProduct2", "inclusive"), &Arc::isInArc_, DEFVAL(true));
    ClassDB::bind_method(D_METHOD("isInArc", "p", "inclusive"), &Arc::isInArc_, DEFVAL(true));
    ClassDB::bind_static_method("Arc", D_METHOD("newArc", "center", "radius", "p1", "p2"), &Arc::newArc);

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "center"), "", "getCenter");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "radius"), "", "getRadius");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "p1"), "", "getP1");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "p2"), "", "getP2");
}

Ref<Point> Arc::getCenter() const {
    RETURN_REF(Point, p, a.center)
}

DCM::uintD Arc::getRadius() const {
    return a.radius;
}

Ref<Point> Arc::getP1() const {
    RETURN_REF(Point, p, a.p1)
}

Ref<Point> Arc::getP2() const {
    RETURN_REF(Point, p, a.p2)
}

String Arc::toString() const {
    return String(DCM::toString(a).c_str());
}

bool Arc::isInArc_(DCM::intD const signCrossProduct1, DCM::intD const signCrossProduct2, bool const inclusive) const {
    return DCM::isInArc(a, signCrossProduct1, signCrossProduct2, inclusive);
}

bool Arc::isInArc(Ref<Point> const p, bool inclusive) const {
    return DCM::isInArc(a, p->p, inclusive);
}

Ref<Arc> Arc::newArc(Ref<Point> const center, DCM::uintD const radius, Ref<Point> const p1, Ref<Point> const p2) {
    RETURN_REF(Arc, a, (DCM::Arc{center->p, radius, p1->p, p2->p}))
}

Arc::Arc() : a{DCM::Point{0, 0}, 0, DCM::Point{0, 1}, DCM::Point{0, 1}} {}

Arc::Arc(Ref<Point> const center, DCM::uintD const radius, Ref<Point> const p1, Ref<Point> const p2) : a{center->p, radius, p1->p, p2->p} {}