struct object_a {
    unsigned char reserved0[0x1b418];
    int field_1b418[1];
};
extern "C" long long function_3e4e64(object_a* object, int second) {
    object->field_1b418[second] += 1;
    return (long long)second;
}
