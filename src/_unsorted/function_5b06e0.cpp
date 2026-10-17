struct channel_group {
    unsigned char reserved0[0x248];
    void* dsp_248;
};

extern "C" int function_592ef0(channel_group* group, void* dsp);

extern "C" int function_5b06e0(channel_group* group, void* dsp) {
    int result = function_592ef0(group, dsp);
    if (result != 0)
        return result;
    if (dsp == 0 || dsp == group->dsp_248)
        group->dsp_248 = 0;
    return 0;
}
