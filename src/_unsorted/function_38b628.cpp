struct Object2;
struct Object5;

struct Object2 {
    unsigned char reserved0[0xc];
    int field_c;
};

struct Object5 {
    Object2* field_0;
    void *field_8;
    void *field_10;
    void *field_18;
};

extern "C" int function_38b130(void *, void *, void *);

extern "C" int function_38b628(Object5 *object5) {
    int local1 = function_38b130(object5->field_8, object5->field_10, object5->field_18);
    object5->field_0->field_c = local1;
    return local1 != 2;
}
