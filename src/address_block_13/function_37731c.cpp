struct Owner {
    char reserved_0[0x148];
    int field_148;
    int field_14c;
};
struct Value {
    char reserved_0[8];
    int value;
};
extern "C" char function_37731c(Owner* owner, void*, Value* input)
{
    int value = input->value;
    owner->field_14c = 0;
    owner->field_148 = value;
    return 1;
}
