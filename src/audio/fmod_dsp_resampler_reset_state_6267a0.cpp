struct resampler {
    unsigned char reserved0[0x210];
    void* pointer_210;
    unsigned char reserved218[8];
    unsigned long long field_220;
    unsigned char reserved228[0x1C];
    int field_244;
    unsigned long long field_248;
};

extern "C" int fmod_dsp_resampler_reset_state_6267a0(resampler* self, void* pointer) {
    self->field_248 = 0x7FFFFFFF;
    self->field_244 = 0;
    self->field_220 = 0;
    self->pointer_210 = pointer;
    return 0;
}
