struct quantizer {
    unsigned char reserved0[0x38];
    char needs_rebuild;
};

struct decompress_info {
    unsigned char reserved0[0x258];
    quantizer* quant;
};

extern "C" long long new_color_map_2_quant_551f50(decompress_info* info) {
    quantizer* quant = info->quant;
    quant->needs_rebuild = 1;
    return (long long)quant;
}
