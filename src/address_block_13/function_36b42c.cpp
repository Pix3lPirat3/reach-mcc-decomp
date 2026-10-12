struct Owner {
    char reserved_0[0x70];
    long long field_70;
};
struct Result {
    int kind;
    int reserved_4;
    long long value;
};
extern "C" char function_36b42c(Owner* owner, void*, Result* result)
{
    result->value = owner->field_70;
    result->kind = 10;
    return 1;
}
