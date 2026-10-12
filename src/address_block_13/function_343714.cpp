struct Output {
    int kind;
    int reserved_4;
    float value;
};

extern "C" float function_34343c();

extern "C" char function_343714(const void*, long long, Output* output)
{
    output->value = function_34343c();
    output->kind = 2;
    return 1;
}
