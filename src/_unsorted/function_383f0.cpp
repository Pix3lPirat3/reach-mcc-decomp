struct slot_owner {
    unsigned char reserved0[0x2BC];
    unsigned char mask;
    unsigned char reserved2bd[0x103];
    unsigned char slots[8 * 0x58];
};

extern "C" int function_383f0(slot_owner* owner) {
    unsigned char mask = owner->mask;
    unsigned char* slot = owner->slots;
    int count = 0;
    for (int i = 0; i < 8; i++) {
        char flag = 0;
        if (mask & 1)
            flag = *slot & 1;
        if (flag != 0)
            count++;
        slot += 0x58;
    }
    return count;
}
