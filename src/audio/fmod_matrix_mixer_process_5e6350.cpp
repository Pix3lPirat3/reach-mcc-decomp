struct mixer {
    unsigned char reserved0[8];
    int field_8;
    int field_c;
    char field_10;
    unsigned char reserved11[7];
    unsigned char field_18[1];
};

extern "C" long long fmod_dsp_mix_buffers_with_matrix_587f10(void* matrix, void* source, void* destination, char flag, int first, int second, int third, unsigned int length, unsigned int fifth);

extern "C" long long fmod_matrix_mixer_process_5e6350(mixer* self, void* destination, void* source, unsigned int length) {
    return fmod_dsp_mix_buffers_with_matrix_587f10(self->field_18, source, destination, self->field_10, self->field_c, self->field_8, 0, length, 1);
}
