struct Owner {
    char reserved_0[0x17c];
    int field_17c;
    int field_180;
};
struct Value {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36e5b8(Owner* owner, void*, Value* input)
{
    int value = input->value;
    owner->field_180 = 0;
    owner->field_17c = value;
    return 1;
}
