struct Context {
    char reserved[0x80];
    void* field_80;
};

struct Result {
    int kind;
    int reserved4;
    void* value;
};

extern "C" char function_35f318(const Context* context, void*, Result* result)
{
    result->value = context->field_80;
    result->kind = 8;
    return 1;
}
