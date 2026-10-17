struct Object;

struct Object {
    unsigned char reserved0[2];
    char field_2;
    char field_3;
    unsigned char reserved4[4];
    int field_8;
    int field_c;
};

extern "C" char function_5d31c(Object *object) {
    int local1;
    if ((object->field_3 & 1)) {
        return 0;
    }
    local1 = object->field_c;
    char result = 0;
    if (local1 == 127 || local1 == object->field_8) {
        result = object->field_2;
    }
    return result;
}
