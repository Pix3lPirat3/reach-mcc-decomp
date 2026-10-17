struct Context {
    char reserved[0xD21];
    char field_D21;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_35e990(const Context* context, void*, Result* result)
{
    char value = context->field_D21;
    result->kind = 0;
    result->value = value;
    return 1;
}
