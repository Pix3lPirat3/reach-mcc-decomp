struct object_a {
    unsigned char reserved0[0x741];
    bool field_741;
};
extern "C" bool function_e2454(object_a* object) {
    return object->field_741;
}
