struct flagged {
    unsigned char reserved0[0x48];
    unsigned int flags;
};

extern "C" int function_5b37b0(flagged* item) {
    item->flags |= 0x1000000;
    return 0;
}
