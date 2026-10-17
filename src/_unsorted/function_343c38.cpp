struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" int function_3439dc();

extern "C" char function_343c38(const void*, long long, Output* output)
{
    output->value = function_3439dc();
    output->kind = 1;
    return 1;
}
