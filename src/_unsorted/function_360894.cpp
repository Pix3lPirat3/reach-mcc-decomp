struct Result {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_360894(void*, void*, Result* result)
{
    result->kind = 1;
    result->value = 4;
    return 1;
}
