struct Owner {
    char reserved_0[0x260];
    long long field_260;
};
struct Result {
    int kind;
    int reserved_4;
    long long value;
};
extern "C" char function_37da74(Owner* owner, void*, Result* result)
{
    result->value = owner->field_260;
    result->kind = 4;
    return 1;
}
