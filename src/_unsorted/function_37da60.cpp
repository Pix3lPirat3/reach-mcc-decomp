struct Owner {
    char reserved_0[0x188];
    int field_188;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_37da60(Owner* owner, void*, Result* result)
{
    int value = owner->field_188;
    result->kind = 1;
    result->value = value;
    return 1;
}
