extern "C" long long function_893560(void*, unsigned short* slots, short value) {
    int index = 0;
    long long position;
    for (position = 0; position < 3; ++position) {
        if (slots[position] == 0xFFFF) {
            slots[index] = value;
            return index;
        }
        ++index;
    }
    return position;
}
