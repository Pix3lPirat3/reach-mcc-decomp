struct Object;

struct Object {
    unsigned int field_0;
    unsigned char reserved4[4];
    unsigned char field_8;
};

extern "C" unsigned char function_5c7b0();

extern "C" char function_303a6c(long long, long long, Object *object) {
    unsigned char local1;
    local1 = function_5c7b0();
    object->field_0 = 0;
    object->field_8 = local1;
    return 1;
}
