#ifndef DRUNK_CHESS_LOGIC_INTERSECTION_BINDING
#define DRUNK_CHESS_LOGIC_INTERSECTION_BINDING

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "DrunkChessLogic/point.hpp"
#include "DrunkChessLogic/line.hpp"
#include "DrunkChessLogic/circle.hpp"
#include "DrunkChessLogic/intersection.hpp"
#include "pointBinding.h"
#include "lineBinding.h"
#include "circleBinding.h"

class TwoIntersections : public RefCounted {
    GDCLASS(TwoIntersections, RefCounted)
public:
    DCM::Intersection::TwoIntersections t;

protected:
    static void _bind_methods();

public:
    Ref<Point> getI1() const;

    Ref<Point> getI2() const;

    String toString() const;

    TwoIntersections();
};

class IntersectionType : public Object {
    GDCLASS(IntersectionType, Object)

protected:
    static void _bind_methods();

public:
    enum Enum {
        ZERO,
        ONE,
        TWO,
        LINE_SEGMENT,
        RAY,
        LINE,
        CIRCLE,
        ARC
    };

    static DCM::Intersection::Type toDCMEnum(Enum const e);
    static Enum fromDCMEnum(DCM::Intersection::Type const e);
};

VARIANT_ENUM_CAST(IntersectionType::Enum)

class LineLineIntersectionSettings : public Object {
    GDCLASS(LineLineIntersectionSettings, Object)

protected:
    static void _bind_methods();

public:
    enum Enum {
        ANY,
        IN_DIRECTION_OF_P1_OR_ON_L2,
        IN_DIRECTION_OF_P2_OR_ON_L2,
    };

    static DCM::LineLineIntersectionSettings toDCMEnum(Enum const e);
    static Enum fromDCMEnum(DCM::LineLineIntersectionSettings const e);
};

VARIANT_ENUM_CAST(LineLineIntersectionSettings::Enum)

class LineCircleIntersectionSettings : public Object {
    GDCLASS(LineCircleIntersectionSettings, Object)

protected:
    static void _bind_methods();

public:
    enum Enum {
        ANY,
        INSIDE_OR_ON_CIRCLE,
        OUTSIDE_OR_ON_CIRCLE,
    };

    static DCM::LineCircleIntersectionSettings toDCMEnum(Enum const e);
    static Enum fromDCMEnum(DCM::LineCircleIntersectionSettings const e);
};

VARIANT_ENUM_CAST(LineCircleIntersectionSettings::Enum)

class CircleCircleIntersectionSettings : public Object {
    GDCLASS(CircleCircleIntersectionSettings, Object)

protected:
    static void _bind_methods();

public:
    enum Enum {
        ANY,
        INSIDE_OR_ON_C2,
        OUTSIDE_OR_ON_C2,
    };

    static DCM::CircleCircleIntersectionSettings toDCMEnum(Enum const e);
    static Enum fromDCMEnum(DCM::CircleCircleIntersectionSettings const e);
};

VARIANT_ENUM_CAST(CircleCircleIntersectionSettings::Enum)

class Intersection : public RefCounted {
    GDCLASS(Intersection, RefCounted)
public:
    DCM::Intersection i;

protected:
    static void _bind_methods();

public:
    IntersectionType::Enum getType() const;
    
    Ref<Point> getOne() const;

    Ref<TwoIntersections> getTwo() const;

    Ref<LineSegment> getLineSegment() const;

    Ref<Ray> getRay() const;

    Ref<Line> getLine() const;

    Ref<Circle> getCircle() const;

    Ref<Arc> getArc() const;

    String toString() const;

    static Ref<Intersection> intersectLineLine(Ref<Line> const l1, Ref<Line> const l2, LineLineIntersectionSettings::Enum settings);
    static Ref<Intersection> intersectLineRay(Ref<Line> const l1, Ref<Ray> const r2, LineLineIntersectionSettings::Enum settings, bool const inclusive = true);
    static Ref<Intersection> intersectLineLineSegment(Ref<Line> const l1, Ref<LineSegment> const ls2, LineLineIntersectionSettings::Enum settings, bool const inclusive = true);
    static Ref<Intersection> intersectRayRay(Ref<Ray> const r1, Ref<Ray> const r2, LineLineIntersectionSettings::Enum settings, bool const inclusive = true);
    static Ref<Intersection> intersectRayLineSegment(Ref<Ray> const r1, Ref<LineSegment> const ls2, LineLineIntersectionSettings::Enum settings, bool const inclusive = true);
    static Ref<Intersection> intersectLineSegmentLineSegment(Ref<LineSegment> const ls1, Ref<LineSegment> const ls2, LineLineIntersectionSettings::Enum settings, bool const inclusive = true);
    
    static Ref<Intersection> intersectLineCircle(Ref<Line> const l, Ref<Circle> const c, LineCircleIntersectionSettings::Enum const settings);
    static Ref<Intersection> intersectLineArc(Ref<Line> const l, Ref<Arc> const a, LineCircleIntersectionSettings::Enum const settings, bool const inclusive = true);
    static Ref<Intersection> intersectRayCircle(Ref<Ray> const r, Ref<Circle> const c, LineCircleIntersectionSettings::Enum const settings, bool const inclusive = true);
    static Ref<Intersection> intersectLineSegmentCircle(Ref<LineSegment> const ls, Ref<Circle> const c, LineCircleIntersectionSettings::Enum const settings, bool const inclusive = true);
    static Ref<Intersection> intersectRayArc(Ref<Ray> const r, Ref<Arc> const a, LineCircleIntersectionSettings::Enum const settings, bool const inclusive = true);
    static Ref<Intersection> intersectLineSegmentArc(Ref<LineSegment> const ls, Ref<Arc> const a, LineCircleIntersectionSettings::Enum const settings, bool const inclusive = true);

    static Ref<Intersection> intersectCircleCircle(Ref<Circle> const c1, Ref<Circle> const c2, CircleCircleIntersectionSettings::Enum const settings);
    static Ref<Intersection> intersectCircleArc(Ref<Circle> const c1, Ref<Arc> const a2, CircleCircleIntersectionSettings::Enum const settings, bool const inclusive);
    static Ref<Intersection> intersectArcCircle(Ref<Arc> const a1, Ref<Circle> const c2, CircleCircleIntersectionSettings::Enum const settings, bool const inclusive);
    static Ref<Intersection> intersectArcArc(Ref<Arc> const a1, Ref<Arc> const a2, CircleCircleIntersectionSettings::Enum const settings, bool const inclusive);

    Intersection();
};

#endif