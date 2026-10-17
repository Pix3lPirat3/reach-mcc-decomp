struct Slot {
    char id;
    char reserved_1;
    char flag;
    char reserved_3[5];
};
struct Owner {
    char reserved_0[0x70];
    unsigned int mode;
    char current;
    char reserved_75[0xf];
    Slot slots[4];
};
struct Result {
    int kind;
    int reserved_4;
    char value;
};
extern "C" char function_3742b8(Owner* owner, void*, Result* result)
{
    char matched;
    if (owner->mode > 3) {
        matched = 0;
    } else {
        long long index = static_cast<int>(owner->mode);
        if (owner->slots[index].flag == 0 || owner->current == owner->slots[index].id)
            matched = 0;
        else
            matched = 1;
    }
    result->kind = 0;
    result->value = matched;
    return 1;
}
