struct Object {
    char reserved_0[0x2b8];
    int field_2b8;
    char reserved_2bc[0x8];
    short field_2c4;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_350a98(Object* object, void*, Value* in)
{
    object->field_2b8 = in->value;
    object->field_2c4 = 0;
    return 1;
}
