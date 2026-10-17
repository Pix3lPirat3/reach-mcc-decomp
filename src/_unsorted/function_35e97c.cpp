struct Context {
    char reserved[0xD20];
    char field_D20;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_35e97c(const Context* context, void*, Result* result)
{
    char value = context->field_D20;
    result->kind = 0;
    result->value = value;
    return 1;
}
