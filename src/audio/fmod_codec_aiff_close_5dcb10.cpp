struct codec {
    unsigned char reserved0[8];
    void* pointer_8;
};

extern "C" int fmod_codec_aiff_close_5dcb10(codec* self) {
    self->pointer_8 = 0;
    return 0;
}
