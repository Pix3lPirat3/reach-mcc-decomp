struct bit_reader;

extern "C" int integer_bit_window_reader_core_dd10c(bit_reader* reader, int bit_count);

extern "C" bool unit_zoom_event_decode_payload_3b87c0(void*, void*, int* payload, bit_reader* reader) {
    *payload = integer_bit_window_reader_core_dd10c(reader, 2) - 1;
    return true;
}
