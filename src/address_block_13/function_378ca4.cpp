struct Owner {
    char reserved_0[0x12aac];
    int field_12aac;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_378ca4(Owner* owner, void*, Result* result)
{
    int value = owner->field_12aac;
    result->kind = 1;
    result->value = value;
    return 1;
}
