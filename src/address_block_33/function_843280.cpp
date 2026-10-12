struct Object8;
struct Object9;

struct Object8 {
    unsigned char reserved0[1];
};

struct Object9 {
    unsigned char reserved0[0x18];
    int field_18;
};

extern "C" int function_843300(int, void *, int);

extern "C" int function_843280(Object9 *object9, Object8 *object8, int value) {
    return (function_843300(object9->field_18, object8, value & -25));
}
