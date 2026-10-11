struct bit_reader;

extern "C" int integer_bit_window_reader_core_dd10c(bit_reader* reader, int bit_count);

extern "C" bool game_engine_statborg_entity_decode_creation_data_4595dc(void*, void*, unsigned int* creation_data, bit_reader* reader) {
    unsigned int value = integer_bit_window_reader_core_dd10c(reader, 5);
    *creation_data = value;
    return value <= 0x17;
}
