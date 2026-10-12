struct Object2;
struct Object;

struct Object2 {
    unsigned int field_0;
    unsigned char reserved4[4];
    unsigned int field_8;
};

struct Object {
    unsigned char reserved0[0x12d0];
    unsigned int field_12d0;
};

extern "C" int function_32aa40(void *, int);

extern "C" bool function_32ac18(Object *object, int value, Object2 *object2) {
    bool result;
    int local1;
    if (value < 0) {
        result = 0;
    } else {
        if (value >= (int)object->field_12d0) {
            return 0;
        }
        local1 = function_32aa40(object, value);
        object2->field_8 = (unsigned int)(local1);
        object2->field_0 = 1;
        result = 1;
    }
    return result;
}
