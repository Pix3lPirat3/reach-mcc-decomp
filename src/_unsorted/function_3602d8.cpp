struct Entry {
    char reserved[0x14];
    int value;
};

struct Context {
    char reserved[0x40E0];
    Entry entry;
    char reserved40F4[0x124];
    char has_entry;
};

struct Result {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3602d8(const Context* context, void*, Result* result)
{
    int value = 0;
    const Entry* entry = context->has_entry ? &context->entry : nullptr;
    if (entry)
        value = entry->value;
    result->kind = 1;
    result->value = value;
    return 1;
}
