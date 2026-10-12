struct Owner {
    char reserved_0[0x990];
    long long field_990;
};
struct Result {
    int kind;
    int reserved_4;
    long long value;
};
extern "C" char function_36b904(Owner* owner, void*, Result* result)
{
    result->value = owner->field_990;
    result->kind = 4;
    return 1;
}
