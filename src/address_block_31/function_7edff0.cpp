struct Object12;
struct Object11;

struct Object12 {
    unsigned char reserved0[0x28];
    Object11* field_28;
};

struct Object11 {
    unsigned char reserved0[1];
};

extern "C" int function_7a8070(void *);

extern "C" int function_7edff0(Object12 *object12) {
    return function_7a8070(object12->field_28);
}
