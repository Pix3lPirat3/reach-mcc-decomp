struct Owner {
    char reserved_0[0x74];
    int field_74;
};
struct Value {
    char reserved_0[8];
    int value;
};
extern "C" void function_3761c4(Owner* owner);
extern "C" char function_376348(Owner* owner, void*, Value* input)
{
    int value = input->value;
    if (value == owner->field_74)
        return 1;
    owner->field_74 = value;
    function_3761c4(owner);
    return 1;
}
