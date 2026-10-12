struct listener {
    unsigned long long field_0;
    unsigned long long field_8;
    unsigned long long field_10;
    unsigned long long field_18;
    int field_20;
    unsigned char reserved24[0xC];
    int field_30;
    int field_34;
    int field_38;
    unsigned char reserved3c[0xC];
    unsigned long long field_48;
    int field_50;
    unsigned char reserved54[0xC];
    unsigned long long field_60;
    int field_68;
};

extern "C" listener* fmod_systemi_listener_init_5f0b00(listener* item) {
    item->field_34 = 0x3F800000;
    item->field_38 = 0;
    item->field_0 = 0;
    item->field_8 = 0;
    item->field_10 = 0;
    item->field_18 = 0;
    item->field_20 = 0;
    item->field_30 = 0;
    item->field_48 = 0;
    item->field_68 = 0;
    item->field_50 = 0x3F800000;
    item->field_60 = 0x3F800000;
    return item;
}
