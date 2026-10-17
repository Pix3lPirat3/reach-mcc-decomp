struct Context {
    char reserved[0x290];
    char field_290;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_360288(const Context* context, void*, Result* result)
{
    char value = context->field_290;
    result->kind = 0;
    result->value = value;
    return 1;
}
