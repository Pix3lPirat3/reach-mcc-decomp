struct Owner {
    char reserved_0[0x280];
    long long field_280;
};
struct Result {
    int kind;
    int reserved_4;
    long long value;
};
extern "C" char function_37dacc(Owner* owner, void*, Result* result)
{
    result->value = owner->field_280;
    result->kind = 4;
    return 1;
}
