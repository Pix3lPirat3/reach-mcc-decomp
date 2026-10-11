struct sound_object {
    unsigned char reserved_0[0xc8];
    void* user_data;
};

extern "C" int fmod_soundi_set_user_data_590050(sound_object* sound, void* user_data) {
    sound->user_data = user_data;
    return 0;
}
