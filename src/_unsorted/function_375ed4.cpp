struct Owner {
    char reserved_0[0x74];
    int field_74;
};
struct Result {
    int kind;
    int reserved_4;
    bool value;
};
extern "C" char function_375ed4(Owner* owner, void*, Result* result)
{
    bool value = owner->field_74 > 1;
    result->kind = 0;
    result->value = value;
    return 1;
}
