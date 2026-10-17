struct array_header {
    void* field_0;
    int field_8;
    unsigned int field_C;
    unsigned char field_10;
};

extern "C" void function_899ca0(array_header* header);

extern "C" void* function_89cf70(void*, void*, array_header* header) {
    if (header != 0) {
        header->field_C = 0x80000000;
        header->field_0 = 0;
        header->field_8 = 0;
    }
    function_899ca0(header);
    return &header->field_10;
}
