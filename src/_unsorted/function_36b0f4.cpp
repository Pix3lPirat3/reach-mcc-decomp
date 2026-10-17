struct Context {
    char reserved[0x680];
    void* field_680;
};

struct Result {
    int kind;
    int reserved4;
    void* value;
};

extern "C" char function_36b0f4(const Context* context, void*, Result* result)
{
    result->value = context->field_680;
    result->kind = 10;
    return 1;
}
