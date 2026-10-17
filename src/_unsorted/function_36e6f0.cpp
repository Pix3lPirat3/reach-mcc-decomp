struct Owner {
    char reserved_0[0x1ac];
    int field_1ac;
    int field_1b0;
};
struct Value {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36e6f0(Owner* owner, void*, Value* input)
{
    int value = input->value;
    owner->field_1b0 = 0;
    owner->field_1ac = value;
    return 1;
}
