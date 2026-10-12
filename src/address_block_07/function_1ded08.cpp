struct flags_holder {
    char reserved0[0x38];
    int flags;
};

extern "C" int function_1ded08(flags_holder* holder, char enable) {
    int old_flags = holder->flags;
    int cleared = old_flags & -9;
    holder->flags = enable == 0 ? cleared : old_flags | 8;
    return cleared;
}
