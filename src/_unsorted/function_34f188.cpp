struct Object {
    char reserved_0[0x218];
    long long field_218;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_34f188(Object* object, void*, Value* out)
{
    out->value = object->field_218;
    out->kind = 4;
    return 1;
}
