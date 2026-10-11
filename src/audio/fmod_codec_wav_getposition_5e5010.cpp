struct wav_codec {
    unsigned char reserved_0[0x224];
    int position;
};

extern "C" int fmod_codec_wav_getposition_5e5010(wav_codec* codec, int* position_out) {
    *position_out = codec->position;
    return 0;
}
