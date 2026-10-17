struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x84];
    bool field_84;
};
extern "C" bool function_2f492c(object_a* object, long long, object_c* input) {
    object->field_84 = input->field_8;
    return true;
}
