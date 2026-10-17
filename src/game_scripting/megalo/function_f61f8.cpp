struct reference_record {
    unsigned char reserved0[3];
    char field_3;
    unsigned char field_4[1];
};

extern "C" int function_dd10c(void* reader, int bits);
extern "C" void function_146f88(void* record, void* reader);
extern "C" void function_1f584c(void * record, void* reader);

extern "C" void function_f61f8(reference_record* record, void* reader) {
    function_1f584c(record, reader);
    record->field_3 = (char)function_dd10c(reader, 4);
    return function_146f88(record->field_4, reader);
}
