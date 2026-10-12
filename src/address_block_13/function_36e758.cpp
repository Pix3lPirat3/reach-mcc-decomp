struct Owner {
    char reserved_0[0x1bc];
    int field_1bc;
    int field_1c0;
};
struct Value {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36e758(Owner* owner, void*, Value* input)
{
    int value = input->value;
    owner->field_1c0 = 0;
    owner->field_1bc = value;
    return 1;
}
