struct Object28;
struct Object27;
struct Object2;

struct Object28 {
    unsigned char reserved0[0x18];
    Object2* field_18;
};

struct Object27 {
    unsigned char reserved0[1];
};

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" int function_7fb040(void *, int, int, void *);

extern "C" int function_7fa240(Object28 *object28, int value, int value2, Object2 *object2) {
    return function_7fb040((Object27 *)&object28->field_18, value, value2, object2);
}
