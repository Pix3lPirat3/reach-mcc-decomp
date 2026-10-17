struct Object {
    char reserved_0[0x70];
    unsigned int flags;
};

struct Value {
    int kind;
    int reserved_4;
    char flag;
};

extern "C" char function_34ec8c(Object* object, void*, Value* in)
{
    unsigned int flags = object->flags;
    object->flags = in->flag == 0 ? flags & 0xFFF7FFFFu : flags | 0x80000u;
    return 1;
}
