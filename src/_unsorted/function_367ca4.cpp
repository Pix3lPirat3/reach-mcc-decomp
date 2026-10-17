struct Context {
    char reserved[0x80];
    char changed;
    char reserved81[0x13];
    int value;
};

struct Source {
    int reserved0[2];
    int value;
};

extern "C" char function_367ca4(Context* context, void*, const Source* source)
{
    context->value = source->value;
    context->changed = 1;
    return 1;
}
