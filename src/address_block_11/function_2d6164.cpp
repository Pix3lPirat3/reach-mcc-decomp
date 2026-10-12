struct Object;

struct Object {
    int field_0;
    char field_4;
    unsigned char reserved5[3];
    int field_8;
    int field_c;
    char field_10;
    unsigned char reserved11[3];
    int field_14;
};

extern "C" long long function_2d6164(Object *object, int value, unsigned int value2) {
    char local1 = 0;
    if (value2 == 255) {
        local1 = 15;
    } else if (value2 <= 3) {
        local1 |= 1 << value2;
    }
    object->field_4 = local1;
    object->field_0 = value;
    object->field_8 = 0x8004D;
    object->field_c = 0x28000A;
    object->field_10 = 1;
    object->field_14 = 2;
    return (long long)object;
}
