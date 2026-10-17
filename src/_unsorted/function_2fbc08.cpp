struct name_block {
    char text[0x100];
};

struct header {
    unsigned char reserved0[0x28];
    int field_28;
    int field_2c;
    name_block names[4];
    char field_430;
};

extern "C" long long function_35c3c(void* destination, void* source, long long length);

extern "C" long long function_2fbc08(header* target, int first, void** sources) {
    int index = 0;
    target->field_28 = first;
    long long position = 0;
    target->field_2c = 4;
    long long result;
    do {
        result = function_35c3c(&target->names[index], sources[position], 0x80);
        ++index;
        ++position;
    } while (position < 4);
    target->field_430 = 0;
    return result;
}
