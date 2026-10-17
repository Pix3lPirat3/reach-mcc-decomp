struct Context {
    char reserved[0x9C];
    char field_9C;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_360d98(const Context* context, void*, Result* result)
{
    char value = context->field_9C;
    result->kind = 0;
    result->value = value;
    return 1;
}
