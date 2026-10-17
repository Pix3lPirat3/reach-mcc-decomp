struct Owner {
    char reserved_0[0xb0];
    int field_b0;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_375ae8(Owner* owner, void*, Result* result)
{
    int value = owner->field_b0;
    result->kind = 1;
    result->value = value;
    return 1;
}
