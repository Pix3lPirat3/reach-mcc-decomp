struct Object4;

struct Object4 {
    int field_0;
    unsigned char reserved4[4];
    unsigned char field_8;
};

extern "C" unsigned char function_38b8e0(void *);

extern "C" char function_356abc(void *object3, int, Object4 *object4) {
    unsigned char local1 = function_38b8e0(object3);
    object4->field_0 = 0;
    object4->field_8 = local1;
    return 1;
}
