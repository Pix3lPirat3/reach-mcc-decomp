struct Owner {
    char reserved_0[0x68c];
    int field_68c;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36b380(Owner* owner, void*, Result* result)
{
    int value = owner->field_68c;
    result->kind = 1;
    result->value = value;
    return 1;
}
