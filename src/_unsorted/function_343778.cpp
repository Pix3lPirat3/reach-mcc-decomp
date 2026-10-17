struct Output {
    int kind;
    int reserved_4;
    float value;
};

extern "C" float function_3434ac();

extern "C" char function_343778(const void*, long long, Output* output)
{
    output->value = function_3434ac();
    output->kind = 2;
    return 1;
}
