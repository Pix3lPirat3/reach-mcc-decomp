struct Result {
    int kind;
    int reserved4;
    char* value;
};

extern "C" char function_36669c(char* context, void*, Result* result)
{
    result->kind = 3;
    result->value = context + 0x78;
    return 1;
}
