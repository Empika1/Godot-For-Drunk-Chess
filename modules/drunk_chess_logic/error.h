#ifndef DRUNK_CHESS_LOGIC_ERROR
#define DRUNK_CHESS_LOGIC_ERROR

#include "core/object/class_db.h"
#include "core/object/object.h"

class DCError : public Object {
    GDCLASS(DCError, Object)

protected:
    static void _bind_methods();

public:
    enum Error {
        DC_DEFAULT_ERROR,
        DC_DIVIDE_BY_ZERO
    };
};

VARIANT_ENUM_CAST(DCError::Error)

#endif