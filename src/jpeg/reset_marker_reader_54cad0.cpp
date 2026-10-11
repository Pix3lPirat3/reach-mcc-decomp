struct marker_state {
    unsigned char reserved0[0x18];
    unsigned short field_18;
    unsigned char reserved1a[6];
    unsigned int field_20;
    unsigned char reserved24[0xD4];
    unsigned long long field_f8;
};

struct marker_reader {
    unsigned char reserved0[0x9C];
    unsigned int field_9c;
    unsigned char reserveda0[0x80];
    unsigned long long field_120;
    unsigned char reserved128[0xDC];
    unsigned int field_204;
    unsigned char reserved208[0x28];
    marker_state* state;
};

extern "C" marker_state* reset_marker_reader_54cad0(marker_reader* reader) {
    marker_state* state = reader->state;
    reader->field_120 = 0;
    reader->field_9c = 0;
    reader->field_204 = 0;
    state->field_18 = 0;
    state->field_20 = 0;
    state->field_f8 = 0;
    return state;
}
