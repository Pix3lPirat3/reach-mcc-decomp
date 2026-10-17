struct Owner {
    char reserved_0[0x14c];
    int field_14c;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_3797fc(Owner* owner, void*, Result* result)
{
    result->value = owner->field_14c;
    result->kind = 6;
    return 1;
}
