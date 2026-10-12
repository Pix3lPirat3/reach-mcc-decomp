struct Context {
    char reserved[0x2D09];
    char field_2D09;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_3641bc(const Context* context, void*, Result* result)
{
    char value = context->field_2D09;
    result->kind = 0;
    result->value = value;
    return 1;
}
