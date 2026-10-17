struct Owner {
    char reserved_0[0xd0];
    char field_d0[1];
};
struct Result {
    int kind;
    int reserved_4;
    void* value;
};
extern "C" char function_37b7f4(Owner* owner, void*, Result* result)
{
    result->kind = 3;
    result->value = owner->field_d0;
    return 1;
}
