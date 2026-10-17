struct Output {
    int kind;
    int reserved_4;
    float value;
};

extern "C" long long function_343384(int index, float value);

extern "C" char function_343804(const void*, long long, const Output* input)
{
    function_343384(2, input->value);
    return 1;
}
