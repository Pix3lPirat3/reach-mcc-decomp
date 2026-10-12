struct Owner {
    char reserved_0[0x194];
    int field_194;
    int field_198;
};
struct Value {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36e654(Owner* owner, void*, Value* input)
{
    int value = input->value;
    owner->field_198 = 0;
    owner->field_194 = value;
    return 1;
}
