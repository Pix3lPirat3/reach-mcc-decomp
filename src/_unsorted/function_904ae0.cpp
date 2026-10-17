typedef long long (*handler)(void);

struct slot {
    handler fn;
    unsigned char reserved8[0x18];
};

extern "C" long long function_904ae0(slot* table, long long, unsigned char* op) {
    return table[op[1] + 0xA].fn();
}
