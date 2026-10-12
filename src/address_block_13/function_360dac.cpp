struct Context {
    char reserved[0x9D];
    char field_9D;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_360dac(const Context* context, void*, Result* result)
{
    char value = context->field_9D;
    result->kind = 0;
    result->value = value;
    return 1;
}
