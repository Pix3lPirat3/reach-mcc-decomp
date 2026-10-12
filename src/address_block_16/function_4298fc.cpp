struct pair_block {
    unsigned char reserved0[8];
    unsigned char body[1];
};

extern "C" char function_fdb98(void* left, void* right);

extern "C" char function_4298fc(long long, pair_block* left, pair_block* right) {
    return function_fdb98(left->body, right->body) != 0;
}
