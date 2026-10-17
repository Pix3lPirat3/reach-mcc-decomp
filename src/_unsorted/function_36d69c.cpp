struct Owner {
    char reserved_0[0x70];
    unsigned int flags;
};
struct Value {
    int kind;
    int reserved_4;
    char value;
};
extern "C" char function_36d69c(Owner* owner, void*, Value* input)
{
    char value = input->value;
    unsigned int flags = owner->flags;
    int updated = value == 0 ? flags & 0xFFFDFFFF : flags | 0x20000;
    owner->flags = value == (static_cast<char>(flags >> 17) & 1) ? updated & 0xFFFBFFFF : updated | 0x40000;
    return 1;
}
