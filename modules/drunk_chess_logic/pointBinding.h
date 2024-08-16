#ifndef DRUNK_CHESS_LOGIC_POINT_BINDING
#define DRUNK_CHESS_LOGIC_POINT_BINDING

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "DrunkChessLogic/point.hpp"

namespace DCM = DrunkChessMath;

class Point : public RefCounted {
    GDCLASS(Point, RefCounted)
public:
    DCM::Point p;

protected:
    static void _bind_methods();

public:
    DCM::intD getX() const;

    DCM::intD getY() const;

    Ref<Point> add(Ref<Point> const other) const;

    Ref<Point> subtract(Ref<Point> const other) const;

    DCM::intD dot(Ref<Point> const other) const;

    DCM::intD cross(Ref<Point> const other) const;

    bool equals (Ref<Point> const other) const;

    DCM::uintD lengthSquared() const;

    DCM::uintD distanceSquared(Ref<Point> const other) const;

    bool arePointingInSameDirection(Ref<Point> const other) const;

    bool areCollinear(Ref<Point> const other1, Ref<Point> const other2, Ref<Point> const other3) const;

    String toString() const;

    static Ref<Point> newPoint(DCM::intD x, DCM::intD y);

    Point();

    Point(DCM::Point p_);
};

#endif