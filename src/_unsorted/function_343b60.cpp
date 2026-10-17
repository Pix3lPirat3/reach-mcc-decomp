struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" int function_343914();

extern "C" char function_343b60(const void*, long long, Output* output)
{
    output->value = function_343914();
    output->kind = 1;
    return 1;
}
