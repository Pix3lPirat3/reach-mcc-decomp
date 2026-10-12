struct Context {
    char reserved[0xA78];
    int field_A78;
};

struct Result {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_35e89c(const Context* context, void*, Result* result)
{
    int value = context->field_A78;
    result->kind = 1;
    result->value = value;
    return 1;
}
