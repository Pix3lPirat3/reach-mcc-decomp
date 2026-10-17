struct Object {
    char reserved_0[0x210];
    int field_210;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_34f0a8(Object* object, void*, Value* out)
{
    int number = object->field_210;
    out->kind = 6;
    out->value = number;
    return 1;
}
