struct sound {
    unsigned char reserved0[0x44];
    unsigned int length_44;
};

struct channel {
    unsigned char reserved0[0x28];
    sound* sound_28;
    unsigned char reserved30[0x28];
    unsigned int loop_start_58;
    int loop_count_5c;
};

extern "C" int fmod_channelreal_default_set_loop_points_63be40(channel* self, unsigned int start, int count) {
    if (self->sound_28 == 0)
        return 0x1F;
    unsigned int length = self->sound_28->length_44;
    if (start >= length)
        return 0x1F;
    if (start + count > length)
        return 0x1F;
    self->loop_start_58 = start;
    self->loop_count_5c = count;
    return 0;
}
