struct Context {
    char reserved[0xD23];
    char field_D23;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_35e9b8(const Context* context, void*, Result* result)
{
    char value = context->field_D23;
    result->kind = 0;
    result->value = value;
    return 1;
}
