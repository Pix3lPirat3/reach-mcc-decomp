struct Object;

struct Object {
    int field_0;
    unsigned char reserved4[4];
    char field_8;
};

extern "C" int function_398a64();

extern "C" char function_3392c0(long long, long long, Object *object) {
    char local1 = (char)(function_398a64());
    object->field_0 = 0;
    object->field_8 = (char)local1 == 1;
    return 1;
}
