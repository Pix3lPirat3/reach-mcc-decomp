struct object_a {
    unsigned char reserved0[0x8c];
    unsigned int field_8c;
};

struct object_d {
    unsigned int field_0;
};
extern "C" void function_3e4220(object_a* object, long long, long long, object_d* extra) {
    extra->field_0 = object->field_8c;
}
