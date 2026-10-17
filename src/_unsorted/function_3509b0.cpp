struct Object {
    char reserved_0[0x2a4];
    int field_2a4;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_3509b0(Object* object, void*, Value* out)
{
    int number = object->field_2a4;
    out->kind = 1;
    out->value = number;
    return 1;
}
