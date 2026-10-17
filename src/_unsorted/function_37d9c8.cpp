struct Owner {
    char reserved_0[0x250];
    long long field_250;
};
struct Result {
    int kind;
    int reserved_4;
    long long value;
};
extern "C" char function_37d9c8(Owner* owner, void*, Result* result)
{
    result->value = owner->field_250;
    result->kind = 4;
    return 1;
}
