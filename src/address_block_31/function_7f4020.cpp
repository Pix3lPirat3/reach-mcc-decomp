struct Object3;

struct Object3 {
    unsigned char reserved0[0x78];
    char* field_78;
};

extern "C" long long function_7f4020(long long, long long, Object3 *object3) {
    return (*(long long (**)(void))(object3->field_78 + 0x10))();
}
