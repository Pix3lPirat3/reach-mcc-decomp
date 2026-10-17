struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x19724];
    unsigned int field_19724;
};
extern "C" bool function_33b7d8(object_a* object, long long, object_c* input) {
    object->field_19724 = input->field_8;
    return true;
}
