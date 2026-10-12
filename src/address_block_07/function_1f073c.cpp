struct object_a {
    unsigned char reserved0[2];
    char field_2;
};
extern "C" int function_132d68(int);

extern "C" int function_1f073c(object_a* object) {
    return function_132d68(object->field_2);
}
