struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x290];
    bool field_290;
};
extern "C" bool function_36029c(object_a* object, long long, object_c* input) {
    object->field_290 = input->field_8;
    return true;
}
