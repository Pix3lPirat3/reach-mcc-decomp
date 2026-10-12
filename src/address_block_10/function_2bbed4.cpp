struct Object4;
struct Object3;

struct Object4 {
    unsigned char reserved0[4];
    char field_4;
    unsigned char reserved5[0xbb];
    char field_c0;
    short field_c2;
};

struct Object3 {
    unsigned char reserved0[0x440];
    int field_440;
};

extern "C" char function_2c4154(void *, void *, long long, int);

extern "C" int function_2bbed4(Object3 *object3, Object4 *object4) {
    int result = -1;
    if (object4->field_c2 <= 0 || function_2c4154((void *)&object3->field_440, (void *)&object4->field_c2, (long long)&object4->field_c0, 0)) {
        result = 0 != *(unsigned char *)(object4->field_4 + (char *)object3 + 0x18B8) ? 1 : -1;
    }
    return result;
}
