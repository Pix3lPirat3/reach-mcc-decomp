extern "C" int integer_bit_window_reader_core_dd10c(void* reader, int bit_count);

extern "C" char game_engine_megalo_team_entity_decode_creation_data_458de0(long long, long long, unsigned char* team_index, void* reader) {
    unsigned char value = (char)integer_bit_window_reader_core_dd10c(reader, 4) - 1;
    *team_index = value;
    return value <= 8;
}
