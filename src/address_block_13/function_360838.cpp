struct Inner {
    char reserved[0x78];
    const void* first;
    const void* second;
};

struct Context {
    char reserved[0x78];
    const Inner* inner;
};

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_360838(const Context* context, void*, Result* result)
{
    const Inner* inner = context->inner;
    char equal = 0;
    if (inner) {
        const void* first = inner->first;
        if (first == nullptr || first != inner->second)
            equal = 0;
        else
            equal = 1;
    }
    result->kind = 0;
    result->value = equal;
    return 1;
}
