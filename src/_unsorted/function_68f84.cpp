struct object_a {
    unsigned char reserved0[0x73e];
    unsigned char field_73e;
};
extern "C" unsigned int function_68f84(object_a* object) {
    return ((unsigned char)~object->field_73e) & 1;
}
