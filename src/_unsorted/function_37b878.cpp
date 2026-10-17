struct Owner {
    char reserved_0[0xa84];
    int field_a84;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_37b878(Owner* owner, void*, Result* result)
{
    int value = owner->field_a84;
    result->kind = 1;
    result->value = value;
    return 1;
}
