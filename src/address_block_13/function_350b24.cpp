struct Object {
    char reserved_0[0x2c0];
    int field_2c0;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_350b24(Object* object, void*, Value* out)
{
    int number = object->field_2c0;
    out->kind = 6;
    out->value = number;
    return 1;
}
