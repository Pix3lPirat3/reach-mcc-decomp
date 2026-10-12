struct Object {
    char reserved_0[0x158];
    int field_158;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_34ed38(Object* object, void*, Value* out)
{
    int number = object->field_158;
    out->kind = 1;
    out->value = number;
    return 1;
}
