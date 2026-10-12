extern "C" short function_dfe20(unsigned short* flags, char enable) {
    short old = *flags;
    short cleared = old & -5;
    *flags = enable == 0 ? cleared : old | 4;
    return cleared;
}
