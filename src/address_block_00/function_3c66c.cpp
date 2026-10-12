struct tagged_value {
    unsigned int kind;
    unsigned short number;
    unsigned short marker;
    unsigned char bytes[8];
};

extern "C" int function_3c66c(tagged_value* value) {
    if (value->marker == 0x1111) {
        unsigned long long id = (((((((unsigned long long)value->bytes[0] << 8 | value->bytes[1]) << 8 | value->bytes[2]) << 8 | value->bytes[3]) << 8 | value->bytes[4]) << 8 | value->bytes[5]) << 8 | value->bytes[6]) << 8 | value->bytes[7];
        if (id != 0)
            return -1;
        long long result = (unsigned int)((int)id + 1);
        if (value->number != (unsigned short)result || value->kind > 6)
            return -1;
        return (int)result;
    }
    return -1;
}
