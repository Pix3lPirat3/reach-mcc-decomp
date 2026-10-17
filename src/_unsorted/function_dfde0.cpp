extern "C" short function_dfde0(unsigned short* flags, char enable) {
    short old = *flags;
    short cleared = old & -2;
    *flags = enable == 0 ? cleared : old | 1;
    return cleared;
}
