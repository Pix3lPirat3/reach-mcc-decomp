struct Object5;

struct Object5 {
    unsigned char reserved0[1];
};

extern "C" int function_7b9a40(void *, void *, int);

extern "C" int function_7b99e0(void * value, Object5 *object5) {
    return function_7b9a40(value, object5, 0);
}
