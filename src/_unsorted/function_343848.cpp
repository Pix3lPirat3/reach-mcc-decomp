struct Output {
    int kind;
    int reserved_4;
    float value;
};

extern "C" float function_343594();

extern "C" char function_343848(const void*, long long, Output* output)
{
    output->value = function_343594();
    output->kind = 2;
    return 1;
}
