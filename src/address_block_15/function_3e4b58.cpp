struct object_a {
    unsigned char reserved0[0x1f898];
    int field_1f898[1];
};
extern "C" long long function_3e4b58(object_a* object, int second) {
    object->field_1f898[second] = -1;
    return (long long)second;
}
