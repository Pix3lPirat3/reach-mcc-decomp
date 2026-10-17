struct Owner {
    char reserved_0[0x2a0];
    long long field_2a0;
};
struct Result {
    int kind;
    int reserved_4;
    long long value;
};
extern "C" char function_37db24(Owner* owner, void*, Result* result)
{
    result->value = owner->field_2a0;
    result->kind = 4;
    return 1;
}
