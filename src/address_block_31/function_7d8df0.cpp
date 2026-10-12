struct Object;

struct Object {
    unsigned char reserved0[1];
};

extern "C" void function_7fc140(void *, int, int, int, int);

extern "C" long long function_7d8df0(Object *object) {
    function_7fc140(object, 0, 0x43F, 0x80, 2);
    return 1;
}
