struct net_bitstream;
struct projectile_attach_request;
struct projectile_attach_position;

extern "C" char function_461830(projectile_attach_request* request, net_bitstream* stream, char flag);
extern "C" char function_462554(projectile_attach_position* position, net_bitstream* stream);

extern "C" char request_projectile_attach_event_decode_payload_462a68(long long, long long, projectile_attach_request* request, net_bitstream* stream, char flag) {
    function_461830(request, stream, flag);
    function_462554((projectile_attach_position*)((char*)request + 0x1C), stream);
    return 1;
}
