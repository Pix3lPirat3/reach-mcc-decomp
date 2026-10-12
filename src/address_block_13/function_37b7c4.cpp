struct Owner {
    char reserved_0[0xc88];
    char field_c88[1];
};
struct Result {
    int kind;
    int reserved_4;
    void* value;
};
extern "C" char function_37b7c4(Owner* owner, void*, Result* result)
{
    result->kind = 3;
    result->value = owner->field_c88;
    return 1;
}
