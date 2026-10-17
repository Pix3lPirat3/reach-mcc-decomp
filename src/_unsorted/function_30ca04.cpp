struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x238];
    unsigned int field_238;
};
extern "C" bool function_30ca04(object_a* object, long long, object_c* input) {
    object->field_238 = input->field_8;
    return true;
}
