struct Result {
    int kind;
    int reserved4;
    char* value;
};

extern "C" char function_35e964(char* context, void*, Result* result)
{
    result->kind = 3;
    result->value = context + 0xB20;
    return 1;
}
