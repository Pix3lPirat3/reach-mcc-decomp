extern "C" short function_dfe00(unsigned short* flags, char enable) {
    short old = *flags;
    short cleared = old & -3;
    *flags = enable == 0 ? cleared : old | 2;
    return cleared;
}
