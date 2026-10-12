struct Context {
    char reserved[0x1F4];
    int field_1F4;
};

struct Result {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_36b1c8(const Context* context, void*, Result* result)
{
    int value = context->field_1F4;
    result->kind = 1;
    result->value = value;
    return 1;
}
