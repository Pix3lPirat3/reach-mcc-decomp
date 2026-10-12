struct channel_state {
    unsigned char reserved0[0x128];
    unsigned long long delay_start;
    unsigned long long delay_end;
    unsigned char stop_flag;
};

extern "C" long long function_592600(const channel_state* channel, unsigned long long* start, unsigned long long* end, unsigned char* flag) {
    if (start != 0)
        *start = channel->delay_start;
    if (end != 0)
        *end = channel->delay_end;
    if (flag == 0)
        return 0;
    *flag = channel->stop_flag;
    return 0;
}
