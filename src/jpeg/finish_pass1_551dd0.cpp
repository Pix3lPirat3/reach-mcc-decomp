struct quantize_pass_state {
    unsigned char reserved0[32];
    void* color_table;
    int color_count;
    unsigned char reserved2c[4];
    void* reserved30;
    unsigned char done;
};

struct quantize_context {
    unsigned char reserved0[144];
    void* color_table;
    unsigned char reserved98[448];
    quantize_pass_state* pass;
};

extern "C" long long select_colors_550c40(quantize_context* context, int color_count);

extern "C" long long finish_pass1_551dd0(quantize_context* context) {
    quantize_pass_state* pass = context->pass;
    context->color_table = pass->color_table;
    long long result = select_colors_550c40(context, pass->color_count);
    pass->done = 1;
    return result;
}
