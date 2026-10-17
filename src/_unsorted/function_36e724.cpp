struct Owner {
    char reserved_0[0x1b4];
    int field_1b4;
    int field_1b8;
};
struct Value {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36e724(Owner* owner, void*, Value* input)
{
    int value = input->value;
    owner->field_1b8 = 0;
    owner->field_1b4 = value;
    return 1;
}
