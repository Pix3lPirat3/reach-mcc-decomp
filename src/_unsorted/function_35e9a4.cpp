struct Context {
    char reserved[0xD22];
    char field_D22;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_35e9a4(const Context* context, void*, Result* result)
{
    char value = context->field_D22;
    result->kind = 0;
    result->value = value;
    return 1;
}
