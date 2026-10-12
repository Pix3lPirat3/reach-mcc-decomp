struct Context {
    char reserved[0x89];
    char field_89;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_35f330(const Context* context, void*, Result* result)
{
    char value = context->field_89;
    result->kind = 0;
    result->value = value;
    return 1;
}
