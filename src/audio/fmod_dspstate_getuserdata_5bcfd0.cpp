struct dsp_state {
    unsigned char reserved_0[0x1f0];
    void* user_data;
};

struct dsp_object {
    dsp_state* state;
};

extern "C" int fmod_dspstate_getuserdata_5bcfd0(dsp_object* dsp, void** user_data_out) {
    if (dsp == nullptr)
        return 0x1f;
    if (user_data_out == nullptr)
        return 0x1f;
    *user_data_out = dsp->state->user_data;
    return 0;
}
