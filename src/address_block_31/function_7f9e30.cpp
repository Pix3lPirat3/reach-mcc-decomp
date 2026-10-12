struct Object7;
struct Object5;
struct Object6;
struct Object4;

struct Object7 {
    Object5* field_0;
};

struct Object5 {
    unsigned char reserved0[1];
};

struct Object6 {
    Object4* field_0;
};

struct Object4 {
    unsigned char reserved0[1];
};

extern "C" int function_7d23c0(void *, void *);

extern "C" int function_7f9e30(Object6 *object6, Object7 *object7) {
    return function_7d23c0(object6->field_0, object7->field_0);
}
