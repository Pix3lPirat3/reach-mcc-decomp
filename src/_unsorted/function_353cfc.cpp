struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x78];
    bool field_78;
};
extern "C" bool function_353cfc(object_a* object, long long, object_c* input) {
    object->field_78 = input->field_8;
    return true;
}
