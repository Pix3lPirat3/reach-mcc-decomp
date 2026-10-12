extern "C" short function_dfe60(unsigned short* flags, char enable) {
    short old = *flags;
    short cleared = old & -17;
    *flags = enable == 0 ? cleared : old | 0x10;
    return cleared;
}
