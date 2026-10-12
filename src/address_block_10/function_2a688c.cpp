struct object_a {
    unsigned int field_0;
};
extern "C" unsigned char function_2a688c(object_a* object) {
    return (unsigned char)(((unsigned char)(~((unsigned char)(object->field_0 >> 0xe)))) & 1);
}
