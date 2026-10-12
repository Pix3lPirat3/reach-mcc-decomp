struct Owner {
    char reserved_0[0x698];
    int field_698;
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" char function_36b3bc(Owner* owner, void*, Result* result)
{
    int value = owner->field_698;
    result->kind = 1;
    result->value = value;
    return 1;
}
