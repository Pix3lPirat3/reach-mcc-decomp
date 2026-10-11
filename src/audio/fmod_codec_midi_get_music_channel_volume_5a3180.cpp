struct music_channel {
    unsigned char reserved0[0x2A8];
    int volume;
    unsigned char reserved2AC[0xD4];
};

struct midi_codec {
    unsigned char reserved0[0x500];
    music_channel channels[16];
};

extern "C" int fmod_codec_midi_get_music_channel_volume_5a3180(midi_codec* codec, int channel, int* volume) {
    if ((unsigned int)channel > 0xF)
        return 0x1F;
    if (volume == nullptr)
        return 0x1F;
    *volume = codec->channels[channel].volume;
    return 0;
}
