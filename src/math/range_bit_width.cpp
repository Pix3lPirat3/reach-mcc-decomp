extern "C" __declspec(dllexport) unsigned int hum_reach_range_bit_width(unsigned int count) {
    unsigned int width = 0;
    if (count != 0) {
        --count;
        while (count != 0) {
            count >>= 1;
            ++width;
        }
    }
#ifdef HUM_NEGATIVE_CONTROL
    return width + 1;
#else
    return width;
#endif
}
