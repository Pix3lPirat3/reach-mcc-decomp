struct object_a {
    unsigned char reserved0[0x358];
    unsigned char field_358;
};
extern "C" unsigned char* function_6954c(object_a* object) {
    return &object->field_358;
}
