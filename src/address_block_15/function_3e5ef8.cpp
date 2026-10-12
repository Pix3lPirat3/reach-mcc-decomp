struct object_a {
    unsigned char reserved0[0x89];
    bool field_89;
};

struct object_d {
    bool field_0;
};
extern "C" void function_3e5ef8(object_a* object, long long, long long, object_d* extra) {
    extra->field_0 = object->field_89;
}
