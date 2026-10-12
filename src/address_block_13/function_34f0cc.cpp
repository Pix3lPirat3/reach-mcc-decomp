struct Object {
    char reserved_0[0x214];
    int field_214;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_34f0cc(Object* object, void*, Value* out)
{
    int number = object->field_214;
    out->kind = 6;
    out->value = number;
    return 1;
}
