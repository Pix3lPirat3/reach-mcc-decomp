struct Object5;
struct Object4;

struct Object5 {
    unsigned char reserved0[1];
};

struct Object4 {
    unsigned char reserved0[1];
};

extern "C" int function_7d23c0(void *, void *);

extern "C" int function_7d3f90(Object4 *object4, Object5 *object5) {
    return function_7d23c0(object4, object5);
}
