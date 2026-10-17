struct state {
    char field_0;
    unsigned char reserved1[0x1f];
    short field_20;
    unsigned char reserved22[0x1fe];
    short field_220;
};

extern "C" state* function_2d7abc(state* data) {
    data->field_0 = 0;
    data->field_20 = 0;
    data->field_220 = 0;
    return data;
}
