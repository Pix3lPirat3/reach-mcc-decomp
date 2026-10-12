struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x38c];
    unsigned int field_38c;
};
extern "C" bool function_2f8b50(object_a* object, long long, object_c* input) {
    object->field_38c = input->field_8;
    return true;
}
