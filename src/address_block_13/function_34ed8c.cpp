struct Object {
    char reserved_0[0x188];
    long long field_188;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_34ed8c(Object* object, void*, Value* out)
{
    out->value = object->field_188;
    out->kind = 4;
    return 1;
}
