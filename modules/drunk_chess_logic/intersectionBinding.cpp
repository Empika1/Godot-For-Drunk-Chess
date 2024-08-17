#include <string>
#include "intersectionBinding.h"
#include "returnRef.h"

void IntersectionType::_bind_methods() {
    BIND_ENUM_CONSTANT(ZERO);
    BIND_ENUM_CONSTANT(ONE);
    BIND_ENUM_CONSTANT(TWO);
    BIND_ENUM_CONSTANT(LINE_SEGMENT);
    BIND_ENUM_CONSTANT(RAY);
    BIND_ENUM_CONSTANT(LINE);
    BIND_ENUM_CONSTANT(CIRCLE);
    BIND_ENUM_CONSTANT(ARC);
}

DCM::Intersection::Type IntersectionType::toDCMEnum(Enum const e) {
    switch(e) {
        case Enum::ZERO:
            return DCM::Intersection::Type::ZERO;
        case Enum::ONE:
            return DCM::Intersection::Type::ONE;
        case Enum::TWO:
            return DCM::Intersection::Type::TWO;
        case Enum::LINE_SEGMENT:
            return DCM::Intersection::Type::LINE_SEGMENT;
        case Enum::RAY:
            return DCM::Intersection::Type::RAY;
        case Enum::LINE:
            return DCM::Intersection::Type::LINE;
        case Enum::CIRCLE:
            return DCM::Intersection::Type::CIRCLE;
        default: //case Enum::ARC:
            return DCM::Intersection::Type::ARC;
    }
}

IntersectionType::Enum IntersectionType::fromDCMEnum(DCM::Intersection::Type const e) {
    switch(e) {
        case DCM::Intersection::Type::ZERO:
            return Enum::ZERO;
        case DCM::Intersection::Type::ONE:
            return Enum::ONE;
        case DCM::Intersection::Type::TWO:
            return Enum::TWO;
        case DCM::Intersection::Type::LINE_SEGMENT:
            return Enum::LINE_SEGMENT;
        case DCM::Intersection::Type::RAY:
            return Enum::RAY;
        case DCM::Intersection::Type::LINE:
            return Enum::LINE;
        case DCM::Intersection::Type::CIRCLE:
            return Enum::CIRCLE;
        default: //case DCM::Intersection::Type::ARC:
            return Enum::ARC;
    }
}

void LineLineIntersectionSettings::_bind_methods() {
    BIND_ENUM_CONSTANT(ANY);
    BIND_ENUM_CONSTANT(IN_DIRECTION_OF_P1_OR_ON_L2);
    BIND_ENUM_CONSTANT(IN_DIRECTION_OF_P2_OR_ON_L2);
}

DCM::LineLineIntersectionSettings LineLineIntersectionSettings::toDCMEnum(Enum const e) {
    switch(e) {
        case Enum::ANY:
            return DCM::LineLineIntersectionSettings::ANY;
        case Enum::IN_DIRECTION_OF_P1_OR_ON_L2:
            return DCM::LineLineIntersectionSettings::IN_DIRECTION_OF_P1_OR_ON_L2;
        default: //case Enum::IN_DIRECTION_OF_P2_OR_ON_L2:
            return DCM::LineLineIntersectionSettings::IN_DIRECTION_OF_P2_OR_ON_L2;
    }
}

LineLineIntersectionSettings::Enum LineLineIntersectionSettings::fromDCMEnum(DCM::LineLineIntersectionSettings const e) {
    switch(e) {
        case DCM::LineLineIntersectionSettings::ANY:
            return Enum::ANY;
        case DCM::LineLineIntersectionSettings::IN_DIRECTION_OF_P1_OR_ON_L2:
            return Enum::IN_DIRECTION_OF_P1_OR_ON_L2;
        default: //case DCM::LineLineIntersectionSettings::IN_DIRECTION_OF_P2_OR_ON_L2:
            return Enum::IN_DIRECTION_OF_P2_OR_ON_L2;
    }
}

void LineCircleIntersectionSettings::_bind_methods() {
    BIND_ENUM_CONSTANT(ANY);
    BIND_ENUM_CONSTANT(INSIDE_OR_ON_CIRCLE);
    BIND_ENUM_CONSTANT(OUTSIDE_OR_ON_CIRCLE);
}

DCM::LineCircleIntersectionSettings LineCircleIntersectionSettings::toDCMEnum(Enum const e) {
    switch(e) {
        case Enum::ANY:
            return DCM::LineCircleIntersectionSettings::ANY;
        case Enum::INSIDE_OR_ON_CIRCLE:
            return DCM::LineCircleIntersectionSettings::INSIDE_OR_ON_CIRCLE;
        default: //case Enum::OUTSIDE_OR_ON_CIRCLE:
            return DCM::LineCircleIntersectionSettings::OUTSIDE_OR_ON_CIRCLE;
    }
}

LineCircleIntersectionSettings::Enum LineCircleIntersectionSettings::fromDCMEnum(DCM::LineCircleIntersectionSettings const e) {
    switch(e) {
        case DCM::LineCircleIntersectionSettings::ANY:
            return Enum::ANY;
        case DCM::LineCircleIntersectionSettings::INSIDE_OR_ON_CIRCLE:
            return Enum::INSIDE_OR_ON_CIRCLE;
        default: //case DCM::LineCircleIntersectionSettings::OUTSIDE_OR_ON_CIRCLE:
            return Enum::OUTSIDE_OR_ON_CIRCLE;
    }
}

void CircleCircleIntersectionSettings::_bind_methods() {
    BIND_ENUM_CONSTANT(ANY);
    BIND_ENUM_CONSTANT(INSIDE_OR_ON_C2);
    BIND_ENUM_CONSTANT(OUTSIDE_OR_ON_C2);
}

DCM::CircleCircleIntersectionSettings CircleCircleIntersectionSettings::toDCMEnum(Enum const e) {
    switch(e) {
        case Enum::ANY:
            return DCM::CircleCircleIntersectionSettings::ANY;
        case Enum::INSIDE_OR_ON_C2:
            return DCM::CircleCircleIntersectionSettings::INSIDE_OR_ON_C2;
        default: //case Enum::OUTSIDE_OR_ON_C2:
            return DCM::CircleCircleIntersectionSettings::OUTSIDE_OR_ON_C2;
    }
}

CircleCircleIntersectionSettings::Enum CircleCircleIntersectionSettings::fromDCMEnum(DCM::CircleCircleIntersectionSettings const e) {
    switch(e) {
        case DCM::CircleCircleIntersectionSettings::ANY:
            return Enum::ANY;
        case DCM::CircleCircleIntersectionSettings::INSIDE_OR_ON_C2:
            return Enum::INSIDE_OR_ON_C2;
        default: //case DCM::CircleCircleIntersectionSettings::OUTSIDE_OR_ON_C2:
            return Enum::OUTSIDE_OR_ON_C2;
    }
}

void TwoIntersections::_bind_methods() {
    ClassDB::bind_method(D_METHOD("getI1"), &TwoIntersections::getI1);
    ClassDB::bind_method(D_METHOD("getI2"), &TwoIntersections::getI2);
    ClassDB::bind_method(D_METHOD("toString"), &TwoIntersections::toString);
}

Ref<Point> TwoIntersections::getI1() const {
   RETURN_REF(Point, p, t.i1)
}

Ref<Point> TwoIntersections::getI2() const {
    RETURN_REF(Point, p, t.i2)
}

String TwoIntersections::toString() const {
    return String{DCM::toString(t).c_str()};
}

TwoIntersections::TwoIntersections() : t{DCM::Point{0, 0}, DCM::Point{0, 0}} {}

void Intersection::_bind_methods() {
    ClassDB::bind_method(D_METHOD("getType"), &Intersection::getType);
    ClassDB::bind_method(D_METHOD("getOne"), &Intersection::getOne);
    ClassDB::bind_method(D_METHOD("getTwo"), &Intersection::getTwo);
    ClassDB::bind_method(D_METHOD("getLineSegment"), &Intersection::getLineSegment);
    ClassDB::bind_method(D_METHOD("getRay"), &Intersection::getRay);
    ClassDB::bind_method(D_METHOD("getLine"), &Intersection::getLine);
    ClassDB::bind_method(D_METHOD("getCircle"), &Intersection::getCircle);
    ClassDB::bind_method(D_METHOD("getArc"), &Intersection::getArc);
    ClassDB::bind_method(D_METHOD("toString"), &Intersection::toString);
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectLineLine", "l1", "l2", "settings"), &Intersection::intersectLineLine);
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectLineRay", "l1", "r2", "settings", "inclusive"), &Intersection::intersectLineRay, DEFVAL(true));
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectLineLineSegment", "l1", "ls2", "settings", "inclusive"), &Intersection::intersectLineLineSegment, DEFVAL(true));
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectRayRay", "r1", "r2", "settings", "inclusive"), &Intersection::intersectRayRay, DEFVAL(true));
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectRayLineSegment", "r1", "ls2", "settings", "inclusive"), &Intersection::intersectRayLineSegment, DEFVAL(true));
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectLineSegmentLineSegment", "ls1", "ls2", "settings", "inclusive"), &Intersection::intersectLineSegmentLineSegment, DEFVAL(true));

    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectLineCircle", "l", "c", "settings"), &Intersection::intersectLineCircle);
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectLineArc", "l", "a", "settings", "inclusive"), &Intersection::intersectLineArc, DEFVAL(true));
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectRayCircle", "r", "c", "settings", "inclusive"), &Intersection::intersectRayCircle, DEFVAL(true));
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectLineSegmentCircle", "ls", "c", "settings", "inclusive"), &Intersection::intersectLineSegmentCircle, DEFVAL(true));
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectRayArc", "r", "a", "settings", "inclusive"), &Intersection::intersectRayArc, DEFVAL(true));
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectLineSegmentArc", "ls", "a", "settings", "inclusive"), &Intersection::intersectLineSegmentArc, DEFVAL(true));

    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectCircleCircle", "c1", "c2", "settings"), &Intersection::intersectCircleCircle);
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectCircleArc", "c1", "a2", "settings", "inclusive"), &Intersection::intersectCircleArc, DEFVAL(true));
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectArcCircle", "a1", "c2", "settings", "inclusive"), &Intersection::intersectArcCircle, DEFVAL(true));
    ClassDB::bind_static_method("Intersection", 
        D_METHOD("intersectArcArc", "a1", "a2", "settings", "inclusive"), &Intersection::intersectArcArc, DEFVAL(true));
}

IntersectionType::Enum Intersection::getType() const {
    return IntersectionType::fromDCMEnum(i.type);
}

Ref<Point> Intersection::getOne() const {
    RETURN_REF(Point, p, i.one)
}

Ref<TwoIntersections> Intersection::getTwo() const {
    RETURN_REF(TwoIntersections, t, i.two)
}

Ref<LineSegment> Intersection::getLineSegment() const {
    RETURN_REF(LineSegment, l, i.lineSegment)
}

Ref<Ray> Intersection::getRay() const {
    RETURN_REF(Ray, r, i.ray)
}

Ref<Line> Intersection::getLine() const {
    RETURN_REF(Line, l, i.line)
}

Ref<Circle> Intersection::getCircle() const {
    RETURN_REF(Circle, c, i.circle)
}

Ref<Arc> Intersection::getArc() const {
    RETURN_REF(Arc, a, i.arc)
}

String Intersection::toString() const {
    return String{DCM::toString(i).c_str()};
}

Ref<Intersection> Intersection::intersectLineLine(Ref<Line> const l1, Ref<Line> const l2, LineLineIntersectionSettings::Enum settings) {
    RETURN_REF(Intersection, i, DCM::intersect(l1->l, l2->l, LineLineIntersectionSettings::toDCMEnum(settings)))
}

Ref<Intersection> Intersection::intersectLineRay(Ref<Line> const l1, Ref<Ray> const r2, LineLineIntersectionSettings::Enum settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(l1->l, r2->r, LineLineIntersectionSettings::toDCMEnum(settings), inclusive))
}

Ref<Intersection> Intersection::intersectLineLineSegment(Ref<Line> const l1, Ref<LineSegment> const ls2, LineLineIntersectionSettings::Enum settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(l1->l, ls2->l, LineLineIntersectionSettings::toDCMEnum(settings), inclusive))
}

Ref<Intersection> Intersection::intersectRayRay(Ref<Ray> const r1, Ref<Ray> const r2, LineLineIntersectionSettings::Enum settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(r1->r, r2->r, LineLineIntersectionSettings::toDCMEnum(settings), inclusive))
}

Ref<Intersection> Intersection::intersectRayLineSegment(Ref<Ray> const r1, Ref<LineSegment> const ls2, LineLineIntersectionSettings::Enum settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(r1->r, ls2->l, LineLineIntersectionSettings::toDCMEnum(settings), inclusive))
}

Ref<Intersection> Intersection::intersectLineSegmentLineSegment(Ref<LineSegment> const ls1, Ref<LineSegment> const ls2, LineLineIntersectionSettings::Enum settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(ls1->l, ls2->l, LineLineIntersectionSettings::toDCMEnum(settings), inclusive))
}


Ref<Intersection> Intersection::intersectLineCircle(Ref<Line> const l, Ref<Circle> const c, LineCircleIntersectionSettings::Enum const settings) {
    RETURN_REF(Intersection, i, DCM::intersect(l->l, c->c, LineCircleIntersectionSettings::toDCMEnum(settings)))
}

Ref<Intersection> Intersection::intersectLineArc(Ref<Line> const l, Ref<Arc> const a, LineCircleIntersectionSettings::Enum const settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(l->l, a->a, LineCircleIntersectionSettings::toDCMEnum(settings), inclusive))
}

Ref<Intersection> Intersection::intersectRayCircle(Ref<Ray> const r, Ref<Circle> const c, LineCircleIntersectionSettings::Enum const settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(r->r, c->c, LineCircleIntersectionSettings::toDCMEnum(settings), inclusive))
}

Ref<Intersection> Intersection::intersectLineSegmentCircle(Ref<LineSegment> const ls, Ref<Circle> const c, LineCircleIntersectionSettings::Enum const settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(ls->l, c->c, LineCircleIntersectionSettings::toDCMEnum(settings), inclusive))
}

Ref<Intersection> Intersection::intersectRayArc(Ref<Ray> const r, Ref<Arc> const a, LineCircleIntersectionSettings::Enum const settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(r->r, a->a, LineCircleIntersectionSettings::toDCMEnum(settings), inclusive))
}

Ref<Intersection> Intersection::intersectLineSegmentArc(Ref<LineSegment> const ls, Ref<Arc> const a, LineCircleIntersectionSettings::Enum const settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(ls->l, a->a, LineCircleIntersectionSettings::toDCMEnum(settings), inclusive))
}


Ref<Intersection> Intersection::intersectCircleCircle(Ref<Circle> const c1, Ref<Circle> const c2, CircleCircleIntersectionSettings::Enum settings) {
    RETURN_REF(Intersection, i, DCM::intersect(c1->c, c2->c, CircleCircleIntersectionSettings::toDCMEnum(settings)))
}

Ref<Intersection> Intersection::intersectCircleArc(Ref<Circle> const c1, Ref<Arc> const a2, CircleCircleIntersectionSettings::Enum settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(c1->c, a2->a, CircleCircleIntersectionSettings::toDCMEnum(settings), inclusive))
}

Ref<Intersection> Intersection::intersectArcCircle(Ref<Arc> const a1, Ref<Circle> const c2, CircleCircleIntersectionSettings::Enum settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(a1->a, c2->c, CircleCircleIntersectionSettings::toDCMEnum(settings), inclusive))
}

Ref<Intersection> Intersection::intersectArcArc(Ref<Arc> const a1, Ref<Arc> const a2, CircleCircleIntersectionSettings::Enum settings, bool const inclusive) {
    RETURN_REF(Intersection, i, DCM::intersect(a1->a, a2->a, CircleCircleIntersectionSettings::toDCMEnum(settings), inclusive))
}

Intersection::Intersection() : i{DCM::Intersection{}} {}