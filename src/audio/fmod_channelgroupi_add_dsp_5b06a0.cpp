struct dsp {
    unsigned char reserved0[0x108];
    int type;
};

struct channel_group {
    unsigned char reserved0[0x248];
    dsp* head_dsp;
};

extern "C" long long fmod_channelcontroli_add_dsp_592ab0(channel_group* group, int index, dsp* new_dsp);

extern "C" long long fmod_channelgroupi_add_dsp_5b06a0(channel_group* group, int index, dsp* new_dsp) {
    long long result = fmod_channelcontroli_add_dsp_592ab0(group, index, new_dsp);
    if ((int)result != 0)
        return result;
    if (new_dsp->type == 0x19)
        group->head_dsp = new_dsp;
    return 0;
}
