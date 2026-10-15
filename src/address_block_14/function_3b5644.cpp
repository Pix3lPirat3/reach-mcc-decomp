struct net_bitstream;

extern "C" int function_dd10c(void * stream, int bit_count);

extern "C" char function_3b5644(long long, long long, int* payload, net_bitstream* stream) {
    *payload = function_dd10c(stream, 6);
    return 1;
}
