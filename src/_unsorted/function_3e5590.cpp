struct object_a {
    unsigned char reserved0[0x90];
    unsigned long long field_90;
};

struct object_d {
    unsigned long long field_0;
};
extern "C" void function_3e5590(object_a* object, long long, long long, object_d* extra) {
    extra->field_0 = object->field_90;
}
