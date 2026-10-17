struct Object {
    char reserved_0[0x2a8];
    char field_2a8;
};

struct Value {
    int kind;
    int reserved_4;
    char flag;
};

extern "C" char function_3509d4(Object* object, void*, Value* out)
{
    char flag = object->field_2a8;
    out->kind = 0;
    out->flag = flag;
    return 1;
}
