struct Owner {
    char reserved_0[0x7c];
    int field_7c;
};
struct Value {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_3741ac(Owner* owner, void*, Value* input)
{
    int value = input->value;
    if (value < 0)
        value = 0;
    owner->field_7c = value;
    return 1;
}
