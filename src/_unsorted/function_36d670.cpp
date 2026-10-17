struct Owner {
    char reserved_0[0x150];
    int field_150;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36d670(Owner* owner, void*, Result* result)
{
    result->value = owner->field_150;
    result->kind = 6;
    return 1;
}
