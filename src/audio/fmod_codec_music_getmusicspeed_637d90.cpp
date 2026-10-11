struct music_codec {
    unsigned char reserved0[0xBF4];
    int music_speed;
};

extern "C" int fmod_codec_music_getmusicspeed_637d90(music_codec* codec, int* speed) {
    *speed = codec->music_speed;
    return 0;
}
