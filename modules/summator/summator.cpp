/* summator.cpp */

#include "summator.h"
#include "return2/tworeturn.h"

void Summator::add(int p_value) {
	count += p_value;
}

void Summator::reset() {
	count = 0;
}

int Summator::get_total() const {
	return count;
}

// int Summator::return_2() {
//     return 2;
// }

void Summator::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add", "value"), &Summator::add);
	ClassDB::bind_method(D_METHOD("reset"), &Summator::reset);
	ClassDB::bind_method(D_METHOD("get_total"), &Summator::get_total);
    ClassDB::bind_static_method("Summator", D_METHOD("return_2"), &return_2);
}

Summator::Summator() {
	count = 0;
}

int return_2() {
    return return2();
}