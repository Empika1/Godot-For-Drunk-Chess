#ifndef DRUNK_CHESS_LOGIC_RETURN_REF
#define DRUNK_CHESS_LOGIC_RETURN_REF

#define RETURN_REF(T, field, value) Ref<T> r_____;\
    r_____.instantiate();\
    r_____->field = value;\
    return r_____;

#endif