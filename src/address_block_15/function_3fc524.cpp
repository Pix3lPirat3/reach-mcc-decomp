struct decoded_block {
    int first;
    unsigned char data[4];
};

extern "C" int integer_bit_window_reader_core_dd10c(void* reader, int bit_count);
extern "C" long long c_bitstream__read_raw_data_dcf28(void* reader, void* destination, unsigned int bit_count);

extern "C" char function_3fc524(void* reader, decoded_block* block) {
    block->first = integer_bit_window_reader_core_dd10c(reader, 7);
    c_bitstream__read_raw_data_dcf28(reader, block->data, 0x20);
    return 1;
}
