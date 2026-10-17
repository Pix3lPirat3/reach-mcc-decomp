struct Context {
    char reserved[0x40E0];
    char entry[0x13C];
    char has_entry;
};

struct Result {
    int kind;
    int reserved4;
    const char* value;
};

extern "C" char function_3603cc(const Context* context, void*, Result* result)
{
    char has_entry = context->has_entry;
    result->kind = 12;
    result->value = has_entry ? context->entry : nullptr;
    return 1;
}
