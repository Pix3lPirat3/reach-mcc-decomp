struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" int function_3438b0();

extern "C" char function_343af4(const void*, long long, Output* output)
{
    output->value = function_3438b0();
    output->kind = 1;
    return 1;
}
