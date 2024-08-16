#include <string>
#include "lineBinding.h"

void Line::_bind_methods() {
    ClassDB::bind_method(D_METHOD("getP1"), &Line::getP1);
    ClassDB::bind_method(D_METHOD("getP2"), &Line::getP2);
    ClassDB::bind_method(D_METHOD("toString"), &Line::toString);
    ClassDB::bind_method(D_METHOD("areCollinear", "other"), &Line::areCollinear);
    ClassDB::bind_method(D_METHOD("areParallel", "other"), &Line::areParallel);
    ClassDB::bind_method(D_METHOD("rasterizationNumber", "p"), &Line::rasterizationNumber);
    ClassDB::bind_method(D_METHOD("nthPointOnRasterization", "n"), &Line::nthPointOnRasterization);
    ClassDB::bind_method(D_METHOD("isOnRasterization", "p"), &Line::isOnRasterization);
    ClassDB::bind_method(D_METHOD("nextPointOnRasterization", "prev"), &Line::nextPointOnRasterization);
    ClassDB::bind_method(D_METHOD("previousPointOnRasterization", "prev"), &Line::previousPointOnRasterization);
    ClassDB::bind_static_method("Line", D_METHOD("newLine", "p1", "p2"), &Line::newLine);

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "p1"), "", "getP1");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "p2"), "", "getP2");
}

Ref<Point> Line::getP1() const {
    Ref<Point> r;
    r.instantiate();
    r->p = l.p1;
    return r;
}

Ref<Point> Line::getP2() const {
    Ref<Point> r;
    r.instantiate();
    r->p = l.p2;
    return r;
}

String Line::toString() const {
    return String{DCM::toString(l).c_str()};
}

bool Line::areCollinear(Ref<Line> const other) const {
    return DCM::areCollinear(l, other->l);
}

bool Line::areParallel(Ref<Line> const other) const {
    return DCM::areParallel(l, other->l);
}

DCM::intD Line::rasterizationNumber(Ref<Point> const p) const {
    return DCM::rasterizationNumber(l, p->p);
}

Ref<Point> Line::nthPointOnRasterization(DCM::intD const n) const {
    Ref<Point> r;
    r.instantiate();
    r->p = DCM::nthPointOnRasterization(l, n);
    return r;
}

bool Line::isOnRasterization(Ref<Point> const p) const {
    return DCM::isOnRasterization(l, p->p);
}

Ref<Point> Line::nextPointOnRasterization(Ref<Point> const prev) const {
    Ref<Point> r;
    r.instantiate();
    r->p = DCM::nextPointOnRasterization(l, prev->p);
    return r;
}

Ref<Point> Line::previousPointOnRasterization(Ref<Point> const next) const {
    Ref<Point> r;
    r.instantiate();
    r->p = DCM::previousPointOnRasterization(l, next->p);
    return r;
}

Ref<Line> Line::newLine(Ref<Point> p1, Ref<Point> p2) {
    Ref<Line> r;
    r.instantiate();
    r->l = DCM::Line{p1->p, p2->p};
    return r;
}

//chosen to avoid any division by 0 with a default line
Line::Line() : l{DCM::Point{0, 0}, DCM::Point{1, 0}} {}

Line::Line(Ref<Point> p1, Ref<Point> p2) : l{p1->p, p2->p} {}

void Ray::_bind_methods() {
    ClassDB::bind_method(D_METHOD("getP1"), &Ray::getP1);
    ClassDB::bind_method(D_METHOD("getP2"), &Ray::getP2);
    ClassDB::bind_method(D_METHOD("toString"), &Ray::toString);
    ClassDB::bind_method(D_METHOD("isOnHalfPlane", "p", "inclusive"), &Ray::isOnHalfPlane, DEFVAL(true));
    ClassDB::bind_static_method("Ray", D_METHOD("newRay", "p1", "p2"), &Ray::newRay);

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "p1"), "", "getP1");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "p2"), "", "getP2");
}

Ref<Point> Ray::getP1() const {
    Ref<Point> r_;
    r_.instantiate();
    r_->p = r.p1;
    return r_;
}

Ref<Point> Ray::getP2() const {
    Ref<Point> r_;
    r_.instantiate();
    r_->p = r.p2;
    return r_;
}

String Ray::toString() const {
    return String{DCM::toString(r).c_str()};
}

bool Ray::isOnHalfPlane(Ref<Point> const p, bool const inclusive) const {
    return DCM::isOnHalfPlaneOfRay(r, p->p, inclusive);
}

Ref<Line> Ray::newRay(Ref<Point> p1, Ref<Point> p2) {
    Ref<Ray> r_;
    r_.instantiate();
    r_->r = DCM::Ray{p1->p, p2->p};
    return r_;
}

Ray::Ray() : r{DCM::Point{0, 0}, DCM::Point{1, 0}} {}

Ray::Ray(Ref<Point> p1, Ref<Point> p2) : r{p1->p, p2->p} {}

void LineSegment::_bind_methods() {
    ClassDB::bind_method(D_METHOD("getP1"), &LineSegment::getP1);
    ClassDB::bind_method(D_METHOD("getP2"), &LineSegment::getP2);
    ClassDB::bind_method(D_METHOD("toString"), &LineSegment::toString);
    ClassDB::bind_method(D_METHOD("isOnPlaneSegment", "p", "inclusive"), &LineSegment::isOnPlaneSegment, DEFVAL(true));
    ClassDB::bind_static_method("LineSegment", D_METHOD("newLineSegment", "p1", "p2"), &LineSegment::newLineSegment);

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "p1"), "", "getP1");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "p2"), "", "getP2");
}

Ref<Point> LineSegment::getP1() const {
    Ref<Point> r;
    r.instantiate();
    r->p = l.p1;
    return r;
}

Ref<Point> LineSegment::getP2() const {
    Ref<Point> r;
    r.instantiate();
    r->p = l.p2;
    return r;
}

String LineSegment::toString() const {
    return String{DCM::toString(l).c_str()};
}

bool LineSegment::isOnPlaneSegment(Ref<Point> const p, bool const inclusive) const {
    return DCM::isOnPlaneSegmentOfLineSegment(l, p->p, inclusive);
}

Ref<Line> LineSegment::newLineSegment(Ref<Point> p1, Ref<Point> p2) {
    Ref<LineSegment> r;
    r.instantiate();
    r->l = DCM::LineSegment{p1->p, p2->p};
    return r;
}

LineSegment::LineSegment() : l{DCM::Point{0, 0}, DCM::Point{1, 0}} {}

LineSegment::LineSegment(Ref<Point> p1, Ref<Point> p2) : l{p1->p, p2->p} {}