struct Object2;

struct Object2 {
    int field_0;
    unsigned char reserved4[4];
    unsigned char field_8;
};

extern "C" unsigned char function_323024(void *);

extern "C" char function_323380(void *object, int, Object2 *object2) {
    unsigned char local1 = function_323024(object);
    object2->field_0 = 0;
    object2->field_8 = local1;
    return 1;
}
