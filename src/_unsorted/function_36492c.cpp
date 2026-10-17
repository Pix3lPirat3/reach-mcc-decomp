struct Context {
    char reserved[0xD4];
    int field_D4;
};

struct Result {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_36492c(const Context* context, void*, Result* result)
{
    int value = context->field_D4;
    result->kind = 1;
    result->value = value;
    return 1;
}
