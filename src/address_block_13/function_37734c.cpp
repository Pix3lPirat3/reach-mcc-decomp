struct Owner {
    char reserved_0[0x150];
    int field_150;
    int field_154;
};
struct Value {
    char reserved_0[8];
    int value;
};
extern "C" char function_37734c(Owner* owner, void*, Value* input)
{
    int value = input->value;
    owner->field_154 = 0;
    owner->field_150 = value;
    return 1;
}
