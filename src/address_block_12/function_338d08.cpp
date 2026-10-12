struct Object;

struct Object {
    int field_0;
    unsigned char reserved4[4];
    char field_8;
};

extern "C" int function_2a4738();

extern "C" char function_338d08(long long, long long, Object *object) {
    char local1 = (char)(function_2a4738());
    object->field_0 = 0;
    object->field_8 = (char)local1 == 0;
    return 1;
}
