struct Object {
    char reserved_0[0x160];
    long long field_160;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_3512a4(Object* object, void*, Value* out)
{
    out->value = object->field_160;
    out->kind = 4;
    return 1;
}
