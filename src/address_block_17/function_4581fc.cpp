struct bit_reader;

struct player_loadout_request {
    int first_value;
    int second_value;
};

extern "C" int function_dd10c(void * reader, int bit_count);

extern "C" char function_4581fc(long long, long long, player_loadout_request* request, bit_reader* reader) {
    request->first_value = function_dd10c(reader, 5);
    request->second_value = function_dd10c(reader, 3);
    return 1;
}
