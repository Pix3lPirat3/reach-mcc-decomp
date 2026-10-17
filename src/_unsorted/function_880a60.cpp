extern "C" int function_880a60(unsigned short bits, char index) {
    return (bits >> (index * 5)) & 0x1F;
}
