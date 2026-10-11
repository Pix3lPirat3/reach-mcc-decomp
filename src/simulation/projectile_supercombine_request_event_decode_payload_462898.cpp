extern "C" int net_definition_index_read_3cd34c(void* reader, void* definition, int tag);

extern "C" bool projectile_supercombine_request_event_decode_payload_462898(void* reader, void*, int* payload, void* definition) {
    *payload = net_definition_index_read_3cd34c(reader, definition, 0x70726F6A);
    return true;
}
