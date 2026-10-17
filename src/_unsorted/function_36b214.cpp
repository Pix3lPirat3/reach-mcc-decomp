struct Entry {
    char value;
    char reserved_1[2];
};
struct Owner {
    char reserved_0[0x1f4];
    int count;
    Entry entries[1];
};
struct Result {
    int kind;
    int reserved_4;
    int value;
};
extern "C" short function_36b214(Owner* owner, int index, Result* result)
{
    if (index < 0)
        return 0;
    if (index >= owner->count)
        return 0;
    int value = owner->entries[index].value + 1;
    result->kind = 1;
    result->value = value;
    return 1;
}
