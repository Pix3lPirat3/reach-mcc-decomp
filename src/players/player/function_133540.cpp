struct object_a {
    unsigned char reserved0[0xa];
    char field_a;
};
extern "C" int function_132d68(int);

extern "C" int function_133540(object_a* object) {
    return function_132d68(object->field_a);
}
