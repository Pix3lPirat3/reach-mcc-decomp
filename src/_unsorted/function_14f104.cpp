struct object_a {
    unsigned char reserved0[6];
    unsigned short field_6;
};
extern "C" object_a* function_14f104(object_a* object) {
    object->field_6 = 0;
    return object;
}
