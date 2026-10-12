int BN_num_bits_word(unsigned long long l);
int BN_num_bits_word(unsigned long long l)
{
    unsigned long long x, mask;
    int bits = (l != 0);
    x = l >> 32;
    mask = (0 - x) & (0xffffffffffffffffLL);
    mask = (0 - (mask >> ((8 * 8) - 1)));
    bits += 32 & mask;
    l ^= (x ^ l) & mask;
    x = l >> 16;
    mask = (0 - x) & (0xffffffffffffffffLL);
    mask = (0 - (mask >> ((8 * 8) - 1)));
    bits += 16 & mask;
    l ^= (x ^ l) & mask;
    x = l >> 8;
    mask = (0 - x) & (0xffffffffffffffffLL);
    mask = (0 - (mask >> ((8 * 8) - 1)));
    bits += 8 & mask;
    l ^= (x ^ l) & mask;
    x = l >> 4;
    mask = (0 - x) & (0xffffffffffffffffLL);
    mask = (0 - (mask >> ((8 * 8) - 1)));
    bits += 4 & mask;
    l ^= (x ^ l) & mask;
    x = l >> 2;
    mask = (0 - x) & (0xffffffffffffffffLL);
    mask = (0 - (mask >> ((8 * 8) - 1)));
    bits += 2 & mask;
    l ^= (x ^ l) & mask;
    x = l >> 1;
    mask = (0 - x) & (0xffffffffffffffffLL);
    mask = (0 - (mask >> ((8 * 8) - 1)));
    bits += 1 & mask;
    return bits;
}
