struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x94];
    bool field_94;
};
extern "C" bool function_367674(object_a* object, long long, object_c* input) {
    object->field_94 = input->field_8;
    return true;
}
