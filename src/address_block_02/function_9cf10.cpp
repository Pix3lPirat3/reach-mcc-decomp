struct small_header {
    long long field_0;
    int field_8;
    int field_c;
};

extern "C" small_header* function_9cf10(small_header* header) {
    header->field_0 = 0;
    header->field_8 = 0;
    header->field_c = 0x80000000;
    return header;
}
