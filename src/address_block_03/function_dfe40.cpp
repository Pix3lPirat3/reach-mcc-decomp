extern "C" short function_dfe40(unsigned short* flags, char enable) {
    short old = *flags;
    short cleared = old & -9;
    *flags = enable == 0 ? cleared : old | 8;
    return cleared;
}
