struct Object10;
struct Object9;

struct Object10 {
    unsigned char reserved0[0x28];
    Object9* field_28;
};

struct Object9 {
    unsigned char reserved0[1];
};

extern "C" int function_7c6140(void *, void *, void *);

extern "C" int function_7d53a0(Object10 *object10, void * value, void * value2) {
    return function_7c6140(object10->field_28, value, value2);
}
