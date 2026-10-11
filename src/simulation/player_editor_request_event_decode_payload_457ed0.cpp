struct net_bitstream;
struct player_editor_request;

extern "C" long long function_77f58(player_editor_request* request, net_bitstream* stream);

extern "C" char player_editor_request_event_decode_payload_457ed0(long long, long long, player_editor_request* request, net_bitstream* stream) {
    function_77f58(request, stream);
    return 1;
}
