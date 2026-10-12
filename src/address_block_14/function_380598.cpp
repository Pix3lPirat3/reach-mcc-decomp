struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x7c];
    bool field_7c;
};
extern "C" bool function_380598(object_a* object, long long, object_c* input) {
    object->field_7c = input->field_8;
    return true;
}
