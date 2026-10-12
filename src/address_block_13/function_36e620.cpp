struct Owner {
    char reserved_0[0x18c];
    int field_18c;
    int field_190;
};
struct Value {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36e620(Owner* owner, void*, Value* input)
{
    int value = input->value;
    owner->field_190 = 0;
    owner->field_18c = value;
    return 1;
}
