struct channel_group {
    unsigned char reserved0[0xC0];
    int direct_occlusion;
    int reverb_occlusion;
};

extern "C" int fmod_channelgroupi_get_3d_occlusion_5b0480(channel_group* group, int* direct, int* reverb) {
    if (direct != nullptr)
        *direct = group->direct_occlusion;
    if (reverb == nullptr)
        return 0;
    *reverb = group->reverb_occlusion;
    return 0;
}
