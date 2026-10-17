struct Object {
    char reserved_0[0x2b8];
    int field_2b8;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_350a84(Object* object, void*, Value* out)
{
    int number = object->field_2b8;
    out->kind = 6;
    out->value = number;
    return 1;
}
