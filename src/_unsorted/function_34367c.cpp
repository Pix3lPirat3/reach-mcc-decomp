struct Output {
    int kind;
    int reserved_4;
    char value;
};

extern "C" long long function_3432c8(int index, char value);

extern "C" char function_34367c(const void*, long long, const Output* input)
{
    function_3432c8(0, input->value);
    return 1;
}
