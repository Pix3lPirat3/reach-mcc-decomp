extern "C" bool function_68e48(long long dest, long long source) {
    *(unsigned short*)(dest + 0x73E) = *(unsigned short*)(dest + 0x73E) & -2;
    *(long long*)(dest + 0x4C) = *(long long*)source;
    *(long long*)(dest + 0x54) = *(long long*)(source + 8);
    *(long long*)(dest + 0x70) = *(long long*)(source + 0x10);
    *(long long*)(dest + 0x78) = *(long long*)(source + 0x18);
    return true;
}
