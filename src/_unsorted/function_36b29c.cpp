struct Owner {
    char reserved_0[0x378];
    int field_378;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36b29c(Owner* owner, void*, Result* result)
{
    int value = owner->field_378;
    result->kind = 1;
    result->value = value;
    return 1;
}
