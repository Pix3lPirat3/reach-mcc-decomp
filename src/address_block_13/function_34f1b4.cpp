struct Object {
    char reserved_0[0x228];
    long long field_228;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_34f1b4(Object* object, void*, Value* out)
{
    out->value = object->field_228;
    out->kind = 4;
    return 1;
}
