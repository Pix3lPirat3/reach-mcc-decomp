struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x19720];
    bool field_19720;
};
extern "C" bool function_33b7fc(object_a* object, long long, object_c* input) {
    object->field_19720 = input->field_8;
    return true;
}
