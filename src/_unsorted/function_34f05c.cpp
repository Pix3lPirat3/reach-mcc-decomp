struct Object {
    char reserved_0[0x208];
    long long field_208;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_34f05c(Object* object, void*, Value* out)
{
    out->value = object->field_208;
    out->kind = 4;
    return 1;
}
