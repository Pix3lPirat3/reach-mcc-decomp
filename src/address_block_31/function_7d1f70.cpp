struct Object5;
struct Object4;

struct Object5 {
    unsigned char reserved0[0xa0];
    unsigned char field_a0[16];
};

struct Object4 {
    unsigned char reserved0[1];
};

extern "C" int function_7b96c0(void *, int, void *);

extern "C" int function_7d1f70(Object5 *object5, int value, void * value2) {
    return function_7b96c0((Object4 *)&object5->field_a0[8], value, value2);
}
