struct codec {
    unsigned char reserved0[0x198];
    void* field_198;
};

extern "C" int ov_clear_644070(codec* file, void* state);

extern "C" int fmod_codec_oggvorbis_close_5fe350(codec* self) {
    self->field_198 = 0;
    ov_clear_644070(self, &self->field_198);
    return 0;
}
