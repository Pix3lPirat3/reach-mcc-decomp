struct Object {
    char reserved_0[0x200];
    long long field_200;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_34f010(Object* object, void*, Value* out)
{
    out->value = object->field_200;
    out->kind = 4;
    return 1;
}
