struct Object {
    char reserved_0[0x1d0];
    long long field_1d0;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_34f0f0(Object* object, void*, Value* out)
{
    out->value = object->field_1d0;
    out->kind = 4;
    return 1;
}
