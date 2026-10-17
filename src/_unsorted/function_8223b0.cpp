struct Object30;
struct Object32;
struct Object33;
struct Object34;

struct Object30 {
    unsigned char reserved0[1];
};

struct Object32 {
    unsigned char reserved0[1];
};

struct Object33 {
    unsigned char reserved0[1];
};

struct Object34 {
    unsigned char reserved0[1];
};

extern "C" int function_821f10(void *, void *, void *, void *, void *, int);

extern "C" int function_8223b0(Object30 *object30, Object32 *object32, Object33 *object33, Object34 *object34) {
    return function_821f10(object30, object32, object33, object34, 0, 0);
}
