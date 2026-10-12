struct Object {
    char reserved_0[0x150];
    unsigned int field_150;
};

struct Value {
    int kind;
    int reserved_4;
    unsigned char flag;
};

extern "C" char function_351894(Object* object, void*, Value* out)
{
    unsigned int flags = object->field_150;
    out->kind = 0;
    out->flag = static_cast<unsigned char>((flags >> 6) & 1);
    return 1;
}
