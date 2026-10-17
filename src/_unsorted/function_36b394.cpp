struct Owner {
    char reserved_0[0x690];
    int field_690;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36b394(Owner* owner, void*, Result* result)
{
    int value = owner->field_690;
    result->kind = 1;
    result->value = value;
    return 1;
}
