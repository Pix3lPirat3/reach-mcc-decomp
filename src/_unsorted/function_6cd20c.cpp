struct object_b {
    unsigned char reserved0[0x24];
    bool field_24;
    unsigned char reserved25[1];
    unsigned short field_26;
};
extern "C" bool function_6cd20c(long long, object_b* source) {
    source->field_24 = false;
    source->field_26 = 0;
    return true;
}
