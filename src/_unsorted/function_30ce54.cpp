struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0xac];
    unsigned int field_ac;
};
extern "C" bool function_30ce54(object_a* object, long long, object_c* input) {
    object->field_ac = input->field_8;
    return true;
}
