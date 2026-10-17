struct Owner {
    char reserved_0[0xa0e];
    char field_a0e[1];
};
struct Result {
    int kind;
    int reserved_4;
    void* value;
};
extern "C" char function_37b748(Owner* owner, void*, Result* result)
{
    result->kind = 3;
    result->value = owner->field_a0e;
    return 1;
}
