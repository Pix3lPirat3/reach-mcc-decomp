struct Object {
    char reserved_0[0x1a8];
    long long field_1a8;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_34eebc(Object* object, void*, Value* out)
{
    out->value = object->field_1a8;
    out->kind = 4;
    return 1;
}
