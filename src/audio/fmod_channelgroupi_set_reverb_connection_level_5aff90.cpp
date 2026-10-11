struct system_state {
    unsigned char reserved0[0x1EC];
    float scale;
};

struct dsp_connection;

struct channel_group {
    unsigned char reserved0[0x20];
    system_state* system;
    unsigned char reserved28[0x114];
    float reverb_levels[5];
    dsp_connection* reverb_connections[5];
};

extern "C" long long fmod_dspconnection_set_volume_queued_588ec0(dsp_connection* connection, float volume, int ramp, char flag1, char flag2);

extern "C" long long fmod_channelgroupi_set_reverb_connection_level_5aff90(channel_group* group, int index) {
    dsp_connection* connection = group->reverb_connections[index];
    if (connection != nullptr) {
        long long result = fmod_dspconnection_set_volume_queued_588ec0(connection, group->reverb_levels[index] * group->system->scale, 0x40, 1, 0);
        if ((int)result != 0)
            return result;
        return 0;
    }
    return 0;
}
