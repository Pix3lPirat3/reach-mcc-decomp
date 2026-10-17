struct Source {
    int first;
};

struct Output {
    int kind;
    int reserved_4;
    void* value;
};

extern "C" char function_3473c0(Source* source, long long, Output* output)
{
    output->kind = 3;
    output->value = reinterpret_cast<char*>(source) + 0x88;
    return 1;
}
