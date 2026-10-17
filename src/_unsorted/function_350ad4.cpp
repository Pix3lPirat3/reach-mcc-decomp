struct Object {
    char reserved_0[0x2bc];
    int field_2bc;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_350ad4(Object* object, void*, Value* out)
{
    int number = object->field_2bc;
    out->kind = 6;
    out->value = number;
    return 1;
}
