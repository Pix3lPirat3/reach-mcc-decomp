struct Context {
    char reserved[0x148];
    void* field_148;
};

struct Result {
    int kind;
    int reserved4;
    void* value;
};

extern "C" char function_36a42c(const Context* context, void*, Result* result)
{
    result->value = context->field_148;
    result->kind = 11;
    return 1;
}
