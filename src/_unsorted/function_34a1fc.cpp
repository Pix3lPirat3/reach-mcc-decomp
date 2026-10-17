struct Source {
    int first;
};

struct Output {
    int kind;
    int reserved_4;
    void* value;
};

extern "C" char function_34a1fc(Source* source, long long, Output* output)
{
    output->kind = 4;
    output->value = reinterpret_cast<char*>(source) + 0x64f8;
    return 1;
}
