struct looping_sound_stop_payload {
    int sound_index;
    int value;
};

extern "C" int integer_bit_window_reader_core_dd10c(void* reader, int bit_count);
extern "C" int net_definition_index_read_3cd34c(long long context, void* reader, int tag_group);

extern "C" char scripted_looping_sound_stop_event_decode_payload_467ca4(long long context, long long, looping_sound_stop_payload* payload, void* reader) {
    payload->sound_index = net_definition_index_read_3cd34c(context, reader, 0x6C736E64);
    payload->value = integer_bit_window_reader_core_dd10c(reader, 0x20);
    return 1;
}
