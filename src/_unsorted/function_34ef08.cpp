struct Object {
    char reserved_0[0x1b0];
    long long field_1b0;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_34ef08(Object* object, void*, Value* out)
{
    out->value = object->field_1b0;
    out->kind = 4;
    return 1;
}
