struct Object {
    char reserved_0[0x14c];
    unsigned int field_14c;
};

struct Value {
    int kind;
    int reserved_4;
    unsigned char flag;
};

extern "C" char function_351690(Object* object, void*, Value* out)
{
    unsigned int flags = object->field_14c;
    out->kind = 0;
    out->flag = static_cast<unsigned char>((flags >> 18) & 1);
    return 1;
}
