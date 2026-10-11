struct sample_sound {
    unsigned char reserved_0[0x160];
    void* field_160;
};

extern "C" int fmod_soundi_set_loop_points_58fbc0(sample_sound* sound, unsigned loop_start, int start_unit, unsigned loop_end, unsigned end_unit);
extern "C" int fmod_sample_sound_apply_loop_guard_63c330(sample_sound* sound);
extern "C" int fmod_sample_sound_remove_loop_guard_63c6b0(sample_sound* sound);

extern "C" int fmod_sample_sound_set_loop_points_63c2b0(sample_sound* sound, unsigned loop_start, int start_unit, unsigned loop_end, unsigned end_unit) {
    if (sound->field_160 != nullptr)
        fmod_sample_sound_remove_loop_guard_63c6b0(sound);
    int result = fmod_soundi_set_loop_points_58fbc0(sound, loop_start, start_unit, loop_end, end_unit);
    if (result != 0)
        return result;
    if (sound->field_160 != nullptr)
        fmod_sample_sound_apply_loop_guard_63c330(sound);
    return 0;
}
