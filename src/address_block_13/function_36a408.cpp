struct Context {
    char reserved[0x189];
    char field_189;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_36a408(const Context* context, void*, Result* result)
{
    char value = context->field_189;
    result->kind = 0;
    result->value = value;
    return 1;
}
