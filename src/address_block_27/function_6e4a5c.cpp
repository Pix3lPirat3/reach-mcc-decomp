struct object_b {
    unsigned char reserved0[0x3c];
    bool field_3c;
};
extern "C" bool function_6e4a5c(long long, object_b* source) {
    source->field_3c = false;
    return true;
}
