struct Object;

struct Object {
    unsigned char reserved0[4];
    float field_4;
    int field_8;
    int field_c;
};

extern "C" float function_5d374(Object *object) {
    int local1;
    if ((*(unsigned char *)((char *)object + 3) & 1)) {
        return 0.0;
    }
    local1 = object->field_c;
    float result = 0.0;
    if (local1 == 127 || local1 == object->field_8) {
        result = object->field_4;
    }
    return result;
}
