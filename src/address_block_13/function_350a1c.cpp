struct Object {
    char reserved_0[0x2aa];
    char field_2aa;
};

struct Value {
    int kind;
    int reserved_4;
    char flag;
};

extern "C" char function_350a1c(Object* object, void*, Value* out)
{
    char flag = object->field_2aa;
    out->kind = 0;
    out->flag = flag;
    return 1;
}
