struct respawn_target_payload {
    int first_value;
    int stream_field;
    char reserved8[8];
    char raw_data[1];
};

extern "C" int function_dd10c(void* reader, int bit_count);
extern "C" void function_3c6884(void* reader, void* stream, int bit_count, unsigned char is_writing, unsigned char is_reading, void * extra);
extern "C" void function_dcf28(void* reader, void* destination, int bit_count);

extern "C" char function_45859c(long long, long long, respawn_target_payload* payload, void* reader, unsigned char flag) {
    payload->first_value = function_dd10c(reader, 5);
    function_3c6884(reader, &payload->stream_field, 0x10, flag ^ 1, flag, 0);
    function_dcf28(reader, payload->raw_data, 0x60);
    return 1;
}
