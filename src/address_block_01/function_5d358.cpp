struct Object;

struct Object {
    unsigned short field_0;
    unsigned char reserved2[1];
    char field_3;
    unsigned char reserved4[4];
    int field_8;
    int field_c;
};

extern "C" long long function_5d358(Object *object) {
    int local1;
    if ((object->field_3 & 1) != 0) {
        return 0;
    }
    local1 = object->field_c;
    long long result = 0;
    if (local1 == 127 || local1 == (int)object->field_8) {
        result = object->field_0;
    }
    return result;
}
