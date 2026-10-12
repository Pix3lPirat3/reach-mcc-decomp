struct object_b {
    unsigned char reserved0[4];
    float field_4;
};
extern "C" void hk_store_float_at_offset_4_8ea5d0(float value, object_b* source) {
    source->field_4 = value;
}
