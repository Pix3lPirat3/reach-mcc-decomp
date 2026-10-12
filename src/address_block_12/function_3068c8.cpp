struct source {
    char reserved0[0x23c];
    int field_23c;
    int field_240;
};

extern "C" void function_3068c8(source* object) {
    object->field_240 = -1;
    object->field_23c = 0xbf800000;
}
