struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x81];
    bool field_81;
};
extern "C" bool function_31ae74(object_a* object, long long, object_c* input) {
    object->field_81 = input->field_8;
    return true;
}
