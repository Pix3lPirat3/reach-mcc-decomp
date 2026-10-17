struct Object;

struct Object {
    unsigned char reserved0[0x32];
    unsigned short field_32;
};

extern "C" int function_1f0a54(int);

extern "C" int function_f29bc(Object *object, int value) {
    int local1;
    local1 = function_1f0a54(value);
    object->field_32 = (unsigned short)(local1);
    return (int)local1;
}
