struct channel_control {
    unsigned char reserved0[0x48];
    int mode;
};

extern "C" int fmod_channelcontroli_set_volume_ramp_5921d0(channel_control* channel, char ramp) {
    int mode = channel->mode;
    channel->mode = ramp == 0 ? mode | 0x20 : mode & ~0x20;
    return 0;
}
