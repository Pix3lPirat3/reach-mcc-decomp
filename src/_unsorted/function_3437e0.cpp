struct Output {
    int kind;
    int reserved_4;
    float value;
};

extern "C" float function_343520();

extern "C" char function_3437e0(const void*, long long, Output* output)
{
    output->value = function_343520();
    output->kind = 2;
    return 1;
}
