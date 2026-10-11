struct guid_bytes {
    unsigned long long low;
    unsigned long long high;
};

struct map_variant {
    unsigned char reserved0[0x2B8];
    guid_bytes guid;
};

extern "C" int guid_marker_to_status_code_3c5c4(guid_bytes* guid);
extern "C" char function_d114(guid_bytes* guid);
extern "C" long long function_6c080(map_variant* variant, int status_code);
extern "C" long long map_variant_content_header_init_defaults_70434(map_variant* variant);

extern "C" char map_variant_init_for_guid_6c244(map_variant* variant, guid_bytes* guid) {
    function_6c080(variant, guid_marker_to_status_code_3c5c4(guid));
    variant->guid = *guid;
    long long valid = function_d114(&variant->guid);
    if ((char)valid == 0)
        return (char)valid;
    return (char)map_variant_content_header_init_defaults_70434(variant);
}
