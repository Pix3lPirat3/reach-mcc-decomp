struct pair_block {
    unsigned char reserved0[4];
    unsigned char body[1];
};

extern "C" char s_network_quality_live__compare_and_sanitize_3e93f0(void* left, void* right);

extern "C" char function_3ff56c(pair_block* left, pair_block* right) {
    return s_network_quality_live__compare_and_sanitize_3e93f0(left->body, right->body) != 0;
}
