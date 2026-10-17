struct Object;

struct Object {
    int field_0;
    unsigned char reserved4[4];
    unsigned char field_8;
};

extern "C" unsigned char function_34320c(int);

extern "C" char function_34365c(int, int, Object *object) {
    unsigned char local1 = function_34320c(0);
    object->field_0 = 0;
    object->field_8 = local1;
    return 1;
}
