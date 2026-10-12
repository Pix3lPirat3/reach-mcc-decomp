struct Object;

struct Object {
    unsigned char reserved0[0x12];
    unsigned char field_12;
    unsigned char reserved13[1];
    unsigned char field_14;
};

extern "C" int function_e2608(Object *object) {
    int local1 = object->field_14;
    return !local1 || local1 != 2 ? object->field_12 : 4;
}
