struct Owner {
    char reserved_0[0xa30];
    char field_a30[1];
};
struct Result {
    int kind;
    int reserved_4;
    void* value;
};
extern "C" char function_37b7dc(Owner* owner, void*, Result* result)
{
    result->kind = 3;
    result->value = owner->field_a30;
    return 1;
}
