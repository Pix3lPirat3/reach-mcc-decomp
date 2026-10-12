struct object_a {
    unsigned char reserved0[0xb];
    char field_b;
};
extern "C" int function_133068(int);

extern "C" int function_133578(object_a* object) {
    return function_133068(object->field_b);
}
