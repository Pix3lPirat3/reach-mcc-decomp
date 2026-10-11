struct channel_control {
    unsigned char reserved0[0x170];
    void* user_data;
};

extern "C" int fmod_channelcontroli_set_user_data_5922f0(channel_control* channel, void* user_data) {
    channel->user_data = user_data;
    return 0;
}
