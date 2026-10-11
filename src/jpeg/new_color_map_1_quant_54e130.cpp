struct error_manager {
    unsigned char reserved0[0x28];
    int message_code;
};

struct decompress_info {
    error_manager* error;
};

extern "C" long long new_color_map_1_quant_54e130(decompress_info* info) {
    info->error->message_code = 0x2F;
    return (*(long long (**)())info->error)();
}
