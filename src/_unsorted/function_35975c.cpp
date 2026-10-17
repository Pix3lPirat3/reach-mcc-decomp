struct object_a {
    unsigned char reserved0[0x72ed8];
    unsigned int field_72ed8;
};
extern "C" bool function_35975c(object_a* object) {
    return object->field_72ed8 <= 1;
}
