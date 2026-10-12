struct flags_holder {
    char reserved0[0x38];
    int flags;
};

extern "C" int function_1ded24(flags_holder* holder, char enable) {
    int old_flags = holder->flags;
    int cleared = old_flags & -17;
    holder->flags = enable == 0 ? cleared : old_flags | 0x10;
    return cleared;
}
