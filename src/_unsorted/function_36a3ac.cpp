struct Context {
    char reserved[0x140];
    void* field_140;
};

struct Result {
    int kind;
    int reserved4;
    void* value;
};

extern "C" char function_36a3ac(const Context* context, void*, Result* result)
{
    result->kind = 10;
    result->value = context->field_140;
    return 1;
}
