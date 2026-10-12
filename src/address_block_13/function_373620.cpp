struct Owner {
    char reserved_0[0x7c];
    int field_7c;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_373620(Owner* owner, void*, Result* result)
{
    result->value = owner->field_7c;
    result->kind = 6;
    return 1;
}
