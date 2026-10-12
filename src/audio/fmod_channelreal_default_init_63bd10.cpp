struct channel {
    unsigned char reserved0[8];
    void* pointer_8;
    unsigned char reserved10[0x10];
    void* pointer_20;
    unsigned long long field_28;
    unsigned char reserved30[8];
    unsigned long long field_38;
    int field_40;
    unsigned char reserved44[4];
    unsigned long long field_48;
    int field_50;
    int field_54;
};

extern "C" int fmod_channelreal_default_init_63bd10(channel* self, int value, void* first, void* second) {
    self->field_54 = -1;
    self->field_28 = 0;
    self->field_38 = 0;
    self->field_48 = 0;
    self->field_50 = 0;
    self->pointer_20 = second;
    self->pointer_8 = first;
    self->field_40 = value;
    return 0;
}
