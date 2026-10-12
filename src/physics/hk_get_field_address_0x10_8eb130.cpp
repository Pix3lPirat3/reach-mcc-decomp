struct object_b {
    unsigned char reserved0[0x10];
    unsigned char field_10;
};
extern "C" unsigned char* hk_get_field_address_0x10_8eb130(long long, object_b* source) {
    return &source->field_10;
}
