#ifndef DRUNK_CHESS_LOGIC_LINE_BINDING
#define DRUNK_CHESS_LOGIC_LINE_BINDING

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "DrunkChessLogic/line.hpp"
#include "pointBinding.h"

namespace DCM = DrunkChessMath;

class Line : public RefCounted {
    GDCLASS(Line, RefCounted)
public:
    DCM::Line l;

protected:
    static void _bind_methods();

public:
    Ref<Point> getP1() const;

    Ref<Point> getP2() const;

    String toString() const;

    bool areCollinear(Ref<Line> const other) const;

    bool areParallel(Ref<Line> const other) const;

    DCM::intD rasterizationNumber(Ref<Point> const p) const;

    Ref<Point> nthPointOnRasterization(DCM::intD const n) const;

    bool isOnRasterization(Ref<Point> const p) const;

    Ref<Point> nextPointOnRasterization(Ref<Point> const prev) const;

    Ref<Point> previousPointOnRasterization(Ref<Point> const next) const;

    static Ref<Line> newLine(Ref<Point> p1, Ref<Point> p2);
    
    Line();

    Line(Ref<Point> p1, Ref<Point> p2);
};

class Ray : public RefCounted {
    GDCLASS(Ray, RefCounted)
public:
    DCM::Ray r;

protected:
    static void _bind_methods();

public:
    Ref<Point> getP1() const;

    Ref<Point> getP2() const;

    String toString() const;

    bool isOnHalfPlane(Ref<Point> const p, bool const inclusive = true) const;

    static Ref<Ray> newRay(Ref<Point> p1, Ref<Point> p2);
    
    Ray();

    Ray(Ref<Point> p1, Ref<Point> p2);
};

class LineSegment : public RefCounted {
    GDCLASS(LineSegment, RefCounted)
public:
    DCM::LineSegment l;

protected:
    static void _bind_methods();

public:
    Ref<Point> getP1() const;

    Ref<Point> getP2() const;

    String toString() const;

    bool isOnPlaneSegment(Ref<Point> const p, bool const inclusive = true) const;

    static Ref<LineSegment> newLineSegment(Ref<Point> p1, Ref<Point> p2);
    
    LineSegment();

    LineSegment(Ref<Point> p1, Ref<Point> p2);
};

#endif