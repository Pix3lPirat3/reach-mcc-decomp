struct sound_object {
    unsigned char reserved_0[0x84];
    int inside_angle;
    int outside_angle;
    int outside_volume;
};

extern "C" int fmod_soundi_get_3d_cone_settings_58e2d0(sound_object* sound, int* inside_out, int* outside_out, int* volume_out) {
    if (inside_out != nullptr)
        *inside_out = sound->inside_angle;
    if (outside_out != nullptr)
        *outside_out = sound->outside_angle;
    if (volume_out == nullptr)
        return 0;
    *volume_out = sound->outside_volume;
    return 0;
}
