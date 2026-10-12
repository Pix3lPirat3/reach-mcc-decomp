struct Object {
    char reserved_0[0x2c0];
    int field_2c0;
    char reserved_2c4[0x400];
    short field_6c4;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_350b38(Object* object, void*, Value* in)
{
    object->field_2c0 = in->value;
    object->field_6c4 = 0;
    return 1;
}
