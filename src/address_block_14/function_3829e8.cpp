struct object_a {
    unsigned char reserved0[0x2c];
    int field_2c;
};

struct object_b {
    unsigned char reserved0[0x2c];
    int field_2c;
};
extern "C" bool function_3829e8(object_a* object, object_b* source) {
    return object->field_2c > source->field_2c;
}
