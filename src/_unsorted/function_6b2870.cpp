struct object_d {
    unsigned char reserved0[4];
    unsigned short field_4;
};
extern "C" unsigned int function_6b2870(long long, long long, long long, object_d* extra) {
    return extra->field_4;
}
