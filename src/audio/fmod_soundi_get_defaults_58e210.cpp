struct sound_object {
    unsigned char reserved_0[0x6c];
    float default_frequency;
    int default_priority;
};

extern "C" int fmod_soundi_get_defaults_58e210(sound_object* sound, float* frequency_out, int* priority_out) {
    if (frequency_out != nullptr)
        *frequency_out = sound->default_frequency;
    if (priority_out == nullptr)
        return 0;
    *priority_out = sound->default_priority;
    return 0;
}
