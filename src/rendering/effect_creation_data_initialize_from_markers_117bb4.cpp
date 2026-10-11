struct vector3 {
    float x;
    float y;
    float z;
};

struct effect_creation_data {
    int state;
    int field_4;
    unsigned char reserved8[0x20];
    vector3* field_28;
    int field_30;
    unsigned char reserved34[0x40];
    unsigned short field_74;
    unsigned char reserved76[0xA];
    void* field_80;
};

extern "C" long long effect_creation_data_initialize_11661c(effect_creation_data* data);

extern "C" long long effect_creation_data_initialize_from_markers_117bb4(effect_creation_data* data, int field_4, int field_30, vector3* field_28, void* field_80, unsigned short* marker, int mode) {
    effect_creation_data_initialize_11661c(data);
    data->state = 0;
    data->field_80 = field_80;
    data->field_4 = field_4;
    data->field_30 = field_30;
    data->field_28 = field_28;
    if (mode == 1)
        data->state = 4;
    if (marker == nullptr)
        return 0;
    long long value = *marker;
    data->field_74 = (unsigned short)value;
    return value;
}
