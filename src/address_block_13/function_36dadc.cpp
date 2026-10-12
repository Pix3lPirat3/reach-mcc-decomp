struct Owner {
    char reserved_0[0x78];
    char flags;
};
struct Value {
    int kind;
    int reserved_4;
    char value;
};
extern "C" char function_36dadc(Owner* owner, void*, Value* input)
{
    char flags = owner->flags;
    owner->flags = input->value == 0 ? static_cast<char>(flags & ~0x4) : static_cast<char>(flags | 0x4);
    return 1;
}
