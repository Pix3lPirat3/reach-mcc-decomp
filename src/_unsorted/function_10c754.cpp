struct object_a {
    unsigned char reserved0[4];
    bool field_4;
    unsigned char reserved5[0x17];
    unsigned int field_1c;
    unsigned char reserved20[0xc];
    bool field_2c;
};
extern "C" object_a* function_10c754(object_a* object) {
    object->field_4 = false;
    object->field_1c = 0;
    object->field_2c = false;
    return object;
}
