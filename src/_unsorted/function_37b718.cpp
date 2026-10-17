struct Owner {
    char reserved_0[0xc68];
    char field_c68[1];
};
struct Result {
    int kind;
    int reserved_4;
    void* value;
};
extern "C" char function_37b718(Owner* owner, void*, Result* result)
{
    result->kind = 3;
    result->value = owner->field_c68;
    return 1;
}
