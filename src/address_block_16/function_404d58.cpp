struct object_a {
    unsigned char reserved0[0x60];
    unsigned int field_60;
    unsigned char reserved64[4];
    bool field_68;
    unsigned char reserved69[1];
    unsigned short field_6a;
};
extern "C" object_a* function_404d58(object_a* object) {
    object->field_60 = 0;
    object->field_68 = false;
    object->field_6a = 0;
    return object;
}
