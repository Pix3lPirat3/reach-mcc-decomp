struct Owner {
    char reserved_0[0x184];
    int field_184;
    int field_188;
};
struct Value {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36e5ec(Owner* owner, void*, Value* input)
{
    int value = input->value;
    owner->field_188 = 0;
    owner->field_184 = value;
    return 1;
}
