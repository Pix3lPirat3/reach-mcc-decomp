extern "C" int c_network_session_membership__get_peer_from_managed_channel_39cbf0(void* membership, int channel);

extern "C" char function_395c94(unsigned char* object, int channel) {
    return c_network_session_membership__get_peer_from_managed_channel_39cbf0(object + 0x30, channel) != -1;
}
