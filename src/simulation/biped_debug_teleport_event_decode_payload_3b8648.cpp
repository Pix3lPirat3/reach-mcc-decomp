extern "C" long long forge_editor_event_read_payload_bits_3c6884(long long context, void* stream, int bit_count, char is_writing, char is_reading, long long extra);

extern "C" char biped_debug_teleport_event_decode_payload_3b8648(long long, long long, void* stream, long long context, char flag) {
    forge_editor_event_read_payload_bits_3c6884(context, stream, 0x10, flag ^ 1, flag, 0);
    return 1;
}
