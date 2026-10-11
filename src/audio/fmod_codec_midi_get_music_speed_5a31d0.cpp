struct midi_codec {
    unsigned char reserved0[0x3C98];
    int music_speed;
};

extern "C" int fmod_codec_midi_get_music_speed_5a31d0(midi_codec* codec, int* speed) {
    *speed = codec->music_speed;
    return 0;
}
