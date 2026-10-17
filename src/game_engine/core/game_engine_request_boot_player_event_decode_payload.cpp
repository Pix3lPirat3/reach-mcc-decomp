struct request_boot_player_payload {
    int first_value;
    int second_value;
    short third_value;
};

extern "C" int function_dd10c(void* reader, int bit_count);

extern "C" char function_466cf8(long long, long long, request_boot_player_payload* payload, void* reader) {
    payload->first_value = function_dd10c(reader, 4);
    payload->second_value = function_dd10c(reader, 4);
    payload->third_value = (short)function_dd10c(reader, 4);
    return 1;
}
