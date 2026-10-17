struct Output {
    int kind;
    int reserved_4;
    unsigned short value;
};

extern "C" long long function_343cb4(void* context, long long value, long long input, long long extra);

extern "C" char function_34405c(void* context, long long, const Output* input, long long extra)
{
    function_343cb4(context, input->value, reinterpret_cast<long long>(input), extra);
    return 1;
}
