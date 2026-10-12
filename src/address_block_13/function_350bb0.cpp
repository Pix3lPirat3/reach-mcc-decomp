struct Object {
    char reserved_0[0x8d0];
    int field_8d0;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_350bb0(Object* object, void*, Value* out)
{
    int number = object->field_8d0;
    out->kind = 6;
    out->value = number;
    return 1;
}
