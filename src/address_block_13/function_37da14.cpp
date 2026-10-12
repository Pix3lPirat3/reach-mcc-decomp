struct Owner {
    char reserved_0[0x258];
    long long field_258;
};
struct Result {
    int kind;
    int reserved_4;
    long long value;
};
extern "C" char function_37da14(Owner* owner, void*, Result* result)
{
    result->value = owner->field_258;
    result->kind = 4;
    return 1;
}
