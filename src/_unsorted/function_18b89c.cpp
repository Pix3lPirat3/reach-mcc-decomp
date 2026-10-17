struct object_b {
    unsigned char reserved0[0x3c];
    float field_3c;
};
extern "C" int function_18b89c(long long, object_b* source) {
    return (int)source->field_3c;
}
