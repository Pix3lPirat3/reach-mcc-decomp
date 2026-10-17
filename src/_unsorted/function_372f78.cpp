struct Owner {
    char reserved_0[0x8a];
    unsigned char field_8a;
};
struct Result {
    int kind;
    int reserved_4;
    unsigned char value;
};
extern "C" char function_372f78(Owner* owner, void*, Result* result)
{
    unsigned char value = owner->field_8a;
    result->kind = 0;
    result->value = value;
    return 1;
}
