struct Context {
    char reserved[0x4220];
    void* field_4220;
};

struct Result {
    int kind;
    int reserved4;
    void* value;
};

extern "C" char function_3601a0(const Context* context, void*, Result* result)
{
    result->value = context->field_4220;
    result->kind = 4;
    return 1;
}
