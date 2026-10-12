struct Output {
    int kind;
    int reserved_4;
    float value;
};

extern "C" long long function_343384(int index, float value);

extern "C" char function_34386c(const void*, long long, const Output* input)
{
    function_343384(3, input->value);
    return 1;
}
