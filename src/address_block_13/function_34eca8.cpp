struct Object {
    char reserved_0[0x14c];
    int field_14c;
};

struct Value {
    int kind;
    int reserved_4;
    char flag;
};

extern "C" char function_34eca8(Object* object, void*, Value* out)
{
    bool positive = object->field_14c > 0;
    out->kind = 0;
    out->flag = positive;
    return 1;
}
