struct Context {
    char reserved[0x8C];
    int field_8C;
};

struct Result {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_367618(const Context* context, void*, Result* result)
{
    int value = context->field_8C;
    result->kind = 1;
    result->value = value;
    return 1;
}
