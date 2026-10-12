struct Owner {
    char reserved_0[0x70];
    char field_70[1];
};
struct Result {
    int kind;
    int reserved_4;
    void* value;
};
extern "C" char function_376718(Owner* owner, void*, Result* result)
{
    result->kind = 3;
    result->value = owner->field_70;
    return 1;
}
