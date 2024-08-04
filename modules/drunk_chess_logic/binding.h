#ifndef POINT_H
#define POINT_H

#include "core/object/ref_counted.h"

class Point : public RefCounted {
	GDCLASS(Point, RefCounted);

private:
	union {
        int thinga;
        float thingb;
    };

	Point();

protected:
	static void _bind_methods();

public:
    void set_thinga(int thinga_);
    int get_thinga();
    void set_thingb(float thingb_);
    float get_thingb();
};

#endif