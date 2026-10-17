struct byte_pair {
    unsigned char first;
    unsigned char second;
};

extern "C" bool function_783d4(byte_pair* pair, unsigned short value) {
    if ((unsigned char)value != pair->first)
        return false;
    if ((char)(value >> 8) != (char)pair->second)
        return false;
    return true;
}
