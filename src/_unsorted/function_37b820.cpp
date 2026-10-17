struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_37b820(void*, void*, Result* result)
{
    result->kind = 1;
    result->value = 2;
    return 1;
}
