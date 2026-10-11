struct bit_reader;

extern "C" int integer_bit_window_reader_core_dd10c(bit_reader* reader, int bit_count);

extern "C" char decode_map_variant_chunk_owner_45aa54(long long, long long, int* out_owner, bit_reader* reader) {
    *out_owner = integer_bit_window_reader_core_dd10c(reader, 5) - 1;
    return 1;
}
