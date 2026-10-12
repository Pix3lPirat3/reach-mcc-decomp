struct Owner {
    char reserved_0[0xa78];
    unsigned char field_a78;
};
struct Result {
    int kind;
    int reserved_4;
    unsigned char value;
};
extern "C" char function_37b80c(Owner* owner, void*, Result* result)
{
    unsigned char value = owner->field_a78;
    result->kind = 0;
    result->value = value;
    return 1;
}
