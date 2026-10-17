struct Object {
    char reserved_0[0x14e];
    unsigned char field_14e;
};

struct Value {
    int kind;
    int reserved_4;
    unsigned char flag;
};

extern "C" char function_35162c(Object* object, void*, Value* out)
{
    unsigned char bits = object->field_14e;
    out->kind = 0;
    out->flag = bits & 1;
    return 1;
}
