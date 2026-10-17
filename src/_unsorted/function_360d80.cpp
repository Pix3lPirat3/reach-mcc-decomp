struct Result {
    int kind;
    int reserved4;
    char* value;
};

extern "C" char function_360d80(char* context, void*, Result* result)
{
    result->kind = 3;
    result->value = context + 0x29E;
    return 1;
}
