extern "C" int integer_bit_window_reader_core_dd10c(void* reader, int bit_count);

extern "C" char vehicle_trick_event_decode_payload_4607cc(long long, long long, int* payload, void* reader) {
    *payload = integer_bit_window_reader_core_dd10c(reader, 3);
    return 1;
}
