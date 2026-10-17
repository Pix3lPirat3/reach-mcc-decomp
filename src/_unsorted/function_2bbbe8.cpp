struct Object12;

struct Object12 {
    unsigned char reserved0[0x140];
    int field_140;
    unsigned char reserved144[0x5c];
    int field_1a0;
    unsigned char reserved1a4[0xc0];
    int field_264;
};

extern "C" char function_2bbbe8(Object12 *object12) {
    char result = 1;
    if (object12->field_140 != -1 || object12->field_1a0 != -1 || object12->field_264 != -1) {
        result = 0;
    }
    return result;
}
