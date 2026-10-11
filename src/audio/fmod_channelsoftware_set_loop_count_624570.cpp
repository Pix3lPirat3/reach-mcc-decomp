struct loop_state {
    unsigned char reserved0[0xC];
    int loop_count;
    int generation;
};

struct voice {
    unsigned char reserved0[0x288];
    loop_state* loop;
};

struct channel_software {
    unsigned char reserved0[0x54];
    int loop_count;
    unsigned char reserved58[0x260];
    voice* voice;
};

extern "C" int fmod_channelsoftware_set_loop_count_624570(channel_software* channel, int loop_count) {
    voice* active_voice = channel->voice;
    channel->loop_count = loop_count;
    if (active_voice == nullptr)
        return 0;
    active_voice->loop->loop_count = loop_count;
    loop_state* loop = channel->voice->loop;
    loop->generation = loop->generation + 1;
    return 0;
}
