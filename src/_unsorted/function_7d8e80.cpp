struct Object;

struct Object {
    unsigned char reserved0[1];
};

extern "C" void function_7fc140(void *, int, int, int, int);

extern "C" long long function_7d8e80(Object *object) {
    function_7fc140(object, 0, 0x440, 0xE0, 2);
    return 1;
}
