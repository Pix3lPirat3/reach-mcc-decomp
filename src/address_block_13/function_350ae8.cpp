struct Object {
    char reserved_0[0x2bc];
    int field_2bc;
    char reserved_2c0[0x204];
    short field_4c4;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_350ae8(Object* object, void*, Value* in)
{
    object->field_2bc = in->value;
    object->field_4c4 = 0;
    return 1;
}
