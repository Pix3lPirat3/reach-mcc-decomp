struct Owner {
    char reserved_0[0x8b];
    unsigned char field_8b;
};
struct Result {
    int kind;
    int reserved_4;
    unsigned char value;
};
extern "C" char function_372f9c(Owner* owner, void*, Result* result)
{
    unsigned char value = owner->field_8b;
    result->kind = 0;
    result->value = value;
    return 1;
}
