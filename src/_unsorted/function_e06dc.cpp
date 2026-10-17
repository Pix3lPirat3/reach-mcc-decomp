struct object_a {
    unsigned char reserved0[2];
    unsigned short field_2;
};
extern "C" void function_e06dc(object_a* object, unsigned int second) {
    if (second <= 2) {
        object->field_2 = (unsigned short)second;
    }
}
