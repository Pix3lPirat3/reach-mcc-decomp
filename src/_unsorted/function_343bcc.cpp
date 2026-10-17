struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" int function_343978();

extern "C" char function_343bcc(const void*, long long, Output* output)
{
    output->value = function_343978();
    output->kind = 1;
    return 1;
}
