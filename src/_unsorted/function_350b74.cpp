struct Object {
    char reserved_0[0x8c4];
    int field_8c4;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_350b74(Object* object, void*, Value* out)
{
    int number = object->field_8c4;
    out->kind = 6;
    out->value = number;
    return 1;
}
