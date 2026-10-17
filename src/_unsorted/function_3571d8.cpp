struct Source {
    char reserved0[0x181C];
    int count_a;
    int count_b;
};

struct Out {
    int kind;
    int reserved4;
    char* value;
};

extern "C" char function_3571d8(Source* source, int index, Out* out)
{
    char* entry = nullptr;
    if (index < 0)
        return 0;
    if (index >= source->count_b)
        return 0;
    if (index < source->count_a)
        entry = reinterpret_cast<char*>(source) + 0x81C + (static_cast<long long>(index) << 9);
    out->value = entry;
    out->kind = 3;
    return 1;
}
