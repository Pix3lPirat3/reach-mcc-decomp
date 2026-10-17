struct Owner {
    char reserved_0[0x114];
    int field_114;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_37afc8(Owner* owner, void*, Result* result)
{
    int value = owner->field_114;
    result->kind = 1;
    result->value = value;
    return 1;
}
