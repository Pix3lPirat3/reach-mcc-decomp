struct Object {
    char reserved_0[0x1d8];
    long long field_1d8;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_34f13c(Object* object, void*, Value* out)
{
    out->value = object->field_1d8;
    out->kind = 4;
    return 1;
}
