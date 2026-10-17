struct Object {
    char reserved_0[0x2ab];
    char field_2ab;
};

struct Value {
    int kind;
    int reserved_4;
    char flag;
};

extern "C" char function_350a70(Object* object, void*, Value* out)
{
    char flag = object->field_2ab;
    out->kind = 0;
    out->flag = flag;
    return 1;
}
