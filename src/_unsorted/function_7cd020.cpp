struct Object;
struct Object5;

struct Object {
    unsigned char reserved0[0x20];
    char* field_20;
};

struct Object5 {
    Object* field_0;
};

extern "C" void function_7a6ba0(long long);

extern "C" long long function_7cd020(int value, Object5 *object5) {
    if (value != 3) {
        return 1;
    }
    function_7a6ba0((long long)object5->field_0->field_20);
    return 1;
}
