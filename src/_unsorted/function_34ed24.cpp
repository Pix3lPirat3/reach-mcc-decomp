struct Object {
    char reserved_0[0x154];
    int field_154;
};

struct Value {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_34ed24(Object* object, void*, Value* out)
{
    int number = object->field_154;
    out->kind = 1;
    out->value = number;
    return 1;
}
