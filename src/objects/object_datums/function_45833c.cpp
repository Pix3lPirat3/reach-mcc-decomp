struct player_money_grant_payload {
    int player_index;
    int amount;
};

extern "C" int function_dd10c(void* reader, int bit_count);

extern "C" char function_45833c(long long, long long, player_money_grant_payload* payload, void* reader) {
    payload->player_index = function_dd10c(reader, 5);
    payload->amount = function_dd10c(reader, 0x10);
    return 1;
}
