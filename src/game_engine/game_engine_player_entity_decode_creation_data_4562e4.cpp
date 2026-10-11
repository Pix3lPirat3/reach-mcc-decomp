struct bit_reader;

extern "C" int integer_bit_window_reader_core_dd10c(bit_reader* reader, int bit_count);

extern "C" char game_engine_player_entity_decode_creation_data_4562e4(void*, void*, unsigned short* player_index, bit_reader* reader) {
    unsigned long long value = integer_bit_window_reader_core_dd10c(reader, 5);
    *player_index = static_cast<unsigned short>(value);
    return static_cast<unsigned short>(value) <= 15;
}
