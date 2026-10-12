struct Owner {
    char reserved_0[0x78];
    unsigned char flags;
};
struct Result {
    int kind;
    int reserved_4;
    unsigned char value;
};
extern "C" char function_36db7c(Owner* owner, void*, Result* result)
{
    unsigned char flags = owner->flags;
    result->kind = 0;
    result->value = (flags >> 5) & 1;
    return 1;
}
