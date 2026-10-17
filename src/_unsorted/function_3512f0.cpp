struct Object {
    char reserved_0[0x14c];
    unsigned char field_14c;
};

struct Value {
    int kind;
    int reserved_4;
    unsigned char flag;
};

extern "C" char function_3512f0(Object* object, void*, Value* out)
{
    unsigned char bits = object->field_14c;
    out->kind = 0;
    out->flag = bits & 1;
    return 1;
}
