struct Owner {
    char reserved_0[0x19c];
    int field_19c;
    int field_1a0;
};
struct Value {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36e688(Owner* owner, void*, Value* input)
{
    int value = input->value;
    owner->field_1a0 = 0;
    owner->field_19c = value;
    return 1;
}
