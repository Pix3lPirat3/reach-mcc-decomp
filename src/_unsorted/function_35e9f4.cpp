struct Context {
    char reserved[0xD28];
    int field_D28;
};

struct Result {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_35e9f4(const Context* context, void*, Result* result)
{
    int value = context->field_D28;
    result->kind = 1;
    result->value = value;
    return 1;
}
