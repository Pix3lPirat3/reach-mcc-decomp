struct Context {
    char reserved[0x188];
    char field_188;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_36a3e4(const Context* context, void*, Result* result)
{
    char value = context->field_188;
    result->kind = 0;
    result->value = value;
    return 1;
}
