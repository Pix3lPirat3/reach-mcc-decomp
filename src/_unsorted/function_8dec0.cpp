extern "C" long long function_8dec0(unsigned char* object, long long, unsigned int amount) {
    *(long long*)(object + 0x33BD0) = *(long long*)(object + 0x33BD0) + amount;
    *(long long*)(object + 0x33BD8) = *(long long*)(object + 0x33BD8) - amount;
    return amount;
}
