struct Object {
    char reserved_0[0x16c];
    int field_16c;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_34ed00(Object* object, void*, Value* out)
{
    int number = object->field_16c;
    out->kind = 1;
    out->value = number;
    return 1;
}
