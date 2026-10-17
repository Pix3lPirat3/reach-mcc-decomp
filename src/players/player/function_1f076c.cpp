struct object_a {
    unsigned char reserved0[3];
    char field_3;
};
extern "C" int function_132d68(int);

extern "C" int function_1f076c(object_a* object) {
    return function_132d68(object->field_3);
}
