struct Object {
    char reserved_0[0x14f];
    unsigned char field_14f;
};

struct Value {
    int kind;
    int reserved_4;
    unsigned char flag;
};

extern "C" char function_3517c8(Object* object, void*, Value* out)
{
    unsigned char bits = object->field_14f;
    out->kind = 0;
    out->flag = bits & 1;
    return 1;
}
