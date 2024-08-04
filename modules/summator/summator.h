/* summator.h */

#ifndef SUMMATOR_H
#define SUMMATOR_H

#include "core/object/ref_counted.h"

class Summator : public RefCounted {
	GDCLASS(Summator, RefCounted);

	int count;

protected:
	static void _bind_methods();

public:
	void add(int p_value);
	void reset();
	int get_total() const;
    //static int return_2();

	Summator();
};

int return_2();

#endif // SUMMATOR_H