struct Owner {
    char reserved_0[0xa80];
    int field_a80;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_37b864(Owner* owner, void*, Result* result)
{
    int value = owner->field_a80;
    result->kind = 1;
    result->value = value;
    return 1;
}
