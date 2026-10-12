struct object_state {
    unsigned char reserved0[4];
    unsigned char field_4;
    unsigned char reserved5[0x2B3];
    unsigned char field_2b8;
    unsigned char reserved2b9[0x7F];
    unsigned short field_338;
};

extern "C" object_state* function_87610(object_state* object) {
    object->field_4 = 0;
    object->field_2b8 = 0;
    object->field_338 = 0;
    return object;
}
