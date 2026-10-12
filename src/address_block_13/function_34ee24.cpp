struct Object {
    char reserved_0[0x198];
    long long field_198;
};

struct Value {
    int kind;
    int reserved_4;
    long long value;
};

extern "C" char function_34ee24(Object* object, void*, Value* out)
{
    out->value = object->field_198;
    out->kind = 4;
    return 1;
}
