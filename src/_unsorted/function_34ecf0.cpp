struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x168];
    unsigned int field_168;
};
extern "C" bool function_34ecf0(object_a* object, long long, object_c* input) {
    object->field_168 = input->field_8;
    return true;
}
