struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x9c];
    unsigned int field_9c;
};
extern "C" bool function_305378(object_a* object, long long, object_c* input) {
    object->field_9c = input->field_8;
    return true;
}
