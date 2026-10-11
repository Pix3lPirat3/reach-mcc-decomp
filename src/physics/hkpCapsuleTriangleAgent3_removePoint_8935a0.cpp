extern "C" long long hkpCapsuleTriangleAgent3_removePoint_8935a0(void*, unsigned short* slots, unsigned short point) {
    int slot = 0;
    long long scanned = 0;
    while (slots[scanned] != point) {
        ++slot;
        ++scanned;
        if (scanned < 3)
            continue;
        return scanned;
    }
    slots[slot] = 0xFFFF;
    return slot;
}
