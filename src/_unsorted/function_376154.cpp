struct Owner {
    char reserved_0[0x99];
    unsigned char field_99;
};
struct Result {
    int kind;
    int reserved_4;
    unsigned char value;
};
extern "C" char function_376154(Owner* owner, void*, Result* result)
{
    unsigned char value = owner->field_99;
    result->kind = 0;
    result->value = value;
    return 1;
}
