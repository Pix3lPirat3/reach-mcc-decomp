struct Context {
    char reserved[0x150];
    void* field_150;
};

struct Result {
    int kind;
    int reserved4;
    void* value;
};

extern "C" char function_36a454(const Context* context, void*, Result* result)
{
    result->value = context->field_150;
    result->kind = 8;
    return 1;
}
