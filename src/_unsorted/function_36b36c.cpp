struct Owner {
    char reserved_0[0x688];
    int field_688;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36b36c(Owner* owner, void*, Result* result)
{
    int value = owner->field_688;
    result->kind = 1;
    result->value = value;
    return 1;
}
