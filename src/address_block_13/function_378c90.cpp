struct Owner {
    char reserved_0[0x12aa8];
    int field_12aa8;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_378c90(Owner* owner, void*, Result* result)
{
    int value = owner->field_12aa8;
    result->kind = 1;
    result->value = value;
    return 1;
}
