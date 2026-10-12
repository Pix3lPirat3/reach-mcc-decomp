struct Owner {
    char reserved_0[0x1a4];
    int field_1a4;
    int field_1a8;
};
struct Value {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36e6bc(Owner* owner, void*, Value* input)
{
    int value = input->value;
    owner->field_1a8 = 0;
    owner->field_1a4 = value;
    return 1;
}
