struct Slot {
    char value;
    char reserved1[2];
};

struct Context {
    char reserved[0x70];
    int count;
    Slot slots[1];
};

struct Result {
    int kind;
    int reserved4;
    int value;
};

extern "C" short function_36b150(const Context* context, int index, Result* result)
{
    if (index < 0)
        return 0;
    if (index >= context->count)
        return 0;
    int value = context->slots[index].value + 1;
    result->kind = 1;
    result->value = value;
    return 1;
}
