struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_343a94(const void*, long long, Output* output)
{
    output->kind = 1;
    output->value = 3;
    return 1;
}
