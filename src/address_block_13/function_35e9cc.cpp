struct Context {
    char reserved[0xD24];
    char field_D24;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_35e9cc(const Context* context, void*, Result* result)
{
    char value = context->field_D24;
    result->kind = 0;
    result->value = value;
    return 1;
}
