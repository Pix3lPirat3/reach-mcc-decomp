struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x99];
    bool field_99;
};
extern "C" bool function_376168(object_a* object, long long, object_c* input) {
    object->field_99 = input->field_8;
    return true;
}
