struct sound_object {
    unsigned char reserved_0[0x6c];
    float default_frequency;
    int default_priority;
};

extern "C" int fmod_soundi_set_defaults_58e1f0(sound_object* sound, float frequency, int priority) {
    sound->default_frequency = frequency;
    int clamped = priority >= 0 ? priority : 0;
    sound->default_priority = clamped > 0x100 ? 0x100 : clamped;
    return 0;
}
