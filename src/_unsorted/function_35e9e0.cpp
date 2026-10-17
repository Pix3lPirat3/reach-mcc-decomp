struct Context {
    char reserved[0xD25];
    char field_D25;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_35e9e0(const Context* context, void*, Result* result)
{
    char value = context->field_D25;
    result->kind = 0;
    result->value = value;
    return 1;
}
