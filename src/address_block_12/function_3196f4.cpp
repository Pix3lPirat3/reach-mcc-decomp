struct object_a {
    unsigned char reserved0[0x72];
    bool field_72;
};

struct object_c {
    unsigned int field_0;
    unsigned char reserved4[4];
    bool field_8;
};
extern "C" bool function_3196f4(object_a* object, long long, object_c* input) {
    bool loaded = object->field_72;
    input->field_0 = 0;
    input->field_8 = loaded;
    return true;
}
