struct Object;
struct Object4;

struct Object {
    unsigned char reserved0[0xc];
    int field_c;
};

struct Object4 {
    Object* field_0;
    void *field_8;
    void *field_10;
    int* field_18;
};

extern "C" int function_22a8e4(void *, void *, long long);

extern "C" int function_22b364(Object4 *object4) {
    int local1 = function_22a8e4(object4->field_8, object4->field_10, (long long)object4->field_18);
    object4->field_0->field_c = local1;
    return local1 != 2;
}
