struct connection_slot {
    unsigned char reserved0[0x18];
};

struct mixer_state {
    unsigned char reserved0[0x12538];
    connection_slot slots[4];
};

struct channel {
    unsigned char reserved0[8];
    mixer_state* mixer_8;
    unsigned char reserved10[0x2C];
    unsigned int flags;
    unsigned char reserved40[0x290];
    void* pointer_2d0;
};

extern "C" int function_623d30(channel* self, float value);
extern "C" int fmod_channelsoftware_update_connection_volume_624060(channel* self, connection_slot* slot, float value);

extern "C" int fmod_channelsoftware_update_6241a0(channel* self, float value) {
    if ((self->flags & 0x80) != 0)
        return 0;
    int result = function_623d30(self, value);
    if (result != 0)
        return result;
    if (self->pointer_2d0 == 0)
        return 0;
    for (int i = 0; i < 4; i++) {
        result = fmod_channelsoftware_update_connection_volume_624060(self, &self->mixer_8->slots[i], value);
        if (result != 0)
            return result;
    }
    return 0;
}
