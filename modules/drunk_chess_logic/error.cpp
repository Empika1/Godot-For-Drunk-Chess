#include "error.h"

void DCError::_bind_methods() {
    BIND_ENUM_CONSTANT(DC_DEFAULT_ERROR)
    BIND_ENUM_CONSTANT(DC_DIVIDE_BY_ZERO)
}