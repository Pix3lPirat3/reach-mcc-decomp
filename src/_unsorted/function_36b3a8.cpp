struct Owner {
    char reserved_0[0x694];
    int field_694;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36b3a8(Owner* owner, void*, Result* result)
{
    int value = owner->field_694;
    result->kind = 1;
    result->value = value;
    return 1;
}
