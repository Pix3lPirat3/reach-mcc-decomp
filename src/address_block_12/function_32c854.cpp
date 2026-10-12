struct Object2;
struct Object;

struct Object2 {
    unsigned int field_0;
    unsigned char reserved4[4];
    unsigned int field_8;
};

struct Object {
    unsigned char reserved0[0x15b0];
    unsigned int field_15b0;
};

extern "C" int function_fe6d0(int, int, int);

extern "C" bool function_32c854(Object *object, int value, Object2 *object2) {
    bool result;
    int local1;
    if (value < 0) {
        result = 0;
    } else {
        if (value >= (int)object->field_15b0) {
            return 0;
        }
        local1 = function_fe6d0(*(unsigned int *)((char *)object + (long long)value * 4 + 0x70), 0, 2);
        object2->field_8 = (unsigned int)(local1);
        object2->field_0 = 1;
        result = 1;
    }
    return result;
}
