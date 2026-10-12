struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" long long function_34589c(void* context, int value, long long input, long long extra);

extern "C" char function_346970(void* context, long long, const Output* input, long long extra)
{
    function_34589c(context, input->value, reinterpret_cast<long long>(input), extra);
    return 1;
}
