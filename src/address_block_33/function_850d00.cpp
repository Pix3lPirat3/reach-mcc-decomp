struct Object2;
struct Object;

struct Object2 {
    unsigned char reserved0[0x110];
    unsigned int field_110;
};

struct Object {
    unsigned char reserved0[1];
};

extern "C" int function_867810(int, void *, void *);

extern "C" int function_850d00(Object *object, int value, Object2 *object2) {
    if (object == 0) {
        return -1;
    }
    if (object2 == 0) {
        return -1;
    }
    if ((value - 0x80 & -193) != 0) {
        return -2;
    }
    if (value == 0x140) {
        return -2;
    }
    object2->field_110 = function_867810(value, object, object2);
    return 0;
}
