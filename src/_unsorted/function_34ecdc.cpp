struct Object {
    char reserved_0[0x168];
    int field_168;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_34ecdc(Object* object, void*, Value* out)
{
    int number = object->field_168;
    out->kind = 1;
    out->value = number;
    return 1;
}
