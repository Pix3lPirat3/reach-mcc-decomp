extern "C" int hk_u16_increment_saturating_or_1_910810(int value) {
    return (value != 0xFFFF ? value + 1 : value) | 1;
}
