struct Object {
    char reserved_0[0x1b8];
    long long field_1b8;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_34ef54(Object* object, void*, Value* out)
{
    out->value = object->field_1b8;
    out->kind = 4;
    return 1;
}
