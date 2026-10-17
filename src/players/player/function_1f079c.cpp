struct object_a {
    unsigned char reserved0[4];
    char field_4;
};
extern "C" int function_133068(int);

extern "C" int function_1f079c(object_a* object) {
    return function_133068(object->field_4);
}
