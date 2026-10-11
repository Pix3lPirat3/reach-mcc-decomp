struct weapon_effect_event {
    unsigned int kind;
    unsigned char payload[0x40];
};

extern "C" int integer_bit_window_reader_core_dd10c(void* reader, int bit_count);
extern "C" long long forge_editor_event_read_payload_bits_3c6884(void* reader, void* output, int bit_count, char flag_a, char flag_b, long long extra);

extern "C" char weapon_effect_event_decode_payload_4388b0(long long, long long, weapon_effect_event* event, void* reader, char flag) {
    event->kind = (unsigned int)integer_bit_window_reader_core_dd10c(reader, 1);
    forge_editor_event_read_payload_bits_3c6884(reader, event->payload, 0xC, flag ^ 1, flag, 0);
    return event->kind < 2;
}
