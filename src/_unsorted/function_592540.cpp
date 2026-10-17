struct channel_control {
    unsigned char reserved0[0x38];
    unsigned char mix_matrix[1];
};

extern "C" int function_614ea0(void* matrix, void* out_matrix, void * out_channels, void * in_channels, int stride);

extern "C" int function_592540(channel_control* channel, void* out_matrix, void * out_channels, void * in_channels, int stride) {
    return function_614ea0(channel->mix_matrix, out_matrix, out_channels, in_channels, stride);
}
