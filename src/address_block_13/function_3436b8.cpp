struct Output {
    int kind;
    int reserved_4;
    char value;
};

extern "C" long long function_3432c8(int index, char value);

extern "C" char function_3436b8(const void*, long long, const Output* input)
{
    function_3432c8(1, input->value);
    return 1;
}
