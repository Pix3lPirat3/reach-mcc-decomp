struct object_a {
    unsigned char reserved0[9];
    char field_9;
};
extern "C" int function_132d68(int);

extern "C" int function_133508(object_a* object) {
    return function_132d68(object->field_9);
}
