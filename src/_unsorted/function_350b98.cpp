struct Object {
    char reserved_0[0x8c8];
    long long field_8c8;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_350b98(Object* object, void*, Value* out)
{
    out->value = object->field_8c8;
    out->kind = 4;
    return 1;
}
