#ifndef DRUNK_CHESS_LOGIC_CIRCLE_BINDING
#define DRUNK_CHESS_LOGIC_CIRCLE_BINDING

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "DrunkChessLogic/circle.hpp"
#include "pointBinding.h"

namespace DCM = DrunkChessMath;

class Circle : public RefCounted {
    GDCLASS(Circle, RefCounted)
public:
    DCM::Circle c;

protected:
    static void _bind_methods();

public:
    Ref<Point> getCenter() const;

    DCM::uintD getRadius() const;

    String toString() const;

    DCM::intD rasterizationNumber(Ref<Point> const p) const;

    Ref<Point> nthPointOnRasterization(DCM::intD const n) const;

    bool isOnRasterization(Ref<Point> const p) const;

    Ref<Point> nextPointOnRasterization(Ref<Point> const prev) const;

    Ref<Point> previousPointOnRasterization(Ref<Point> const next) const;

    static Ref<Circle> newCircle(Ref<Point> const center, DCM::uintD const radius);

    Circle();

    Circle(Ref<Point> const center, DCM::uintD const radius);
};

class Arc : public RefCounted {
    GDCLASS(Arc, RefCounted)
public:
    DCM::Arc a;

protected:
    static void _bind_methods();

public:
    Ref<Point> getCenter() const;

    DCM::uintD getRadius() const;

    Ref<Point> getP1() const;

    Ref<Point> getP2() const;

    String toString() const;

    bool isInArc_(DCM::intD const signCrossProduct1, DCM::intD const signCrossProduct2, bool const inclusive = true) const;

    bool isInArc(Ref<Point> const p, bool inclusive = true) const;

    static Ref<Arc> newArc(Ref<Point> const center, DCM::uintD const radius, Ref<Point> const p1, Ref<Point> const p2);

    Arc();

    Arc(Ref<Point> const center, DCM::uintD const radius, Ref<Point> const p1, Ref<Point> const p2);
};

#endif