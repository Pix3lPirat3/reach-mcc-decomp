struct sound_object {
    unsigned char reserved_0[0x90];
    void* rolloff_points;
    int rolloff_count;
};

extern "C" int fmod_soundi_get_3d_custom_rolloff_58e370(sound_object* sound, void** points_out, int* count_out) {
    if (points_out != nullptr)
        *points_out = sound->rolloff_points;
    if (count_out == nullptr)
        return 0;
    *count_out = sound->rolloff_count;
    return 0;
}
