extern "C" int net_definition_index_read_3cd34c(long long context, long long reader, int definition_tag);

extern "C" char scripted_sound_stop_event_decode_payload_467a1c(long long context, long long, int* out_index, long long reader) {
    *out_index = net_definition_index_read_3cd34c(context, reader, 0x736E6421);
    return 1;
}
