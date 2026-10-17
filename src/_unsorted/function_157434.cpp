struct Object2;
struct Object4;

struct Object2 {
    unsigned char reserved0[0xc];
    int field_c;
};

struct Object4 {
    Object2* field_0;
    void *field_8;
};

extern "C" int function_15649c(void *);

extern "C" int function_157434(Object4 *object4) {
    int local1 = function_15649c(object4->field_8);
    object4->field_0->field_c = local1;
    return local1;
}
