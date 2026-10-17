struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0xad];
    bool field_ad;
};
extern "C" bool function_329d54(object_a* object, long long, object_c* input) {
    object->field_ad = input->field_8;
    return true;
}
