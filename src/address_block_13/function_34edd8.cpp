struct Object {
    char reserved_0[0x190];
    long long field_190;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_34edd8(Object* object, void*, Value* out)
{
    out->value = object->field_190;
    out->kind = 4;
    return 1;
}
