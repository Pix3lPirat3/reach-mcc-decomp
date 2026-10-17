struct Object;

struct Object {
    unsigned char reserved0[0x30];
    unsigned short field_30;
};

extern "C" int function_1f09dc(int);

extern "C" int function_f2914(Object *object, int value) {
    int local1;
    local1 = function_1f09dc(value);
    object->field_30 = (unsigned short)(local1);
    return local1;
}
