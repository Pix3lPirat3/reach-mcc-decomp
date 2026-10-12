struct Object2;

struct Object2 {
    int field_0;
    unsigned char reserved4[4];
    unsigned char field_8;
};

extern "C" unsigned char function_38997c(void *);

extern "C" char function_32a34c(void *object, int, Object2 *object2) {
    unsigned char local1 = function_38997c(object);
    object2->field_0 = 0;
    object2->field_8 = local1;
    return 1;
}
