struct Object25;
struct Object24;

struct Object25 {
    int* field_0;
};

struct Object24 {
    unsigned char reserved0[1];
};

extern "C" int function_7d9370(void *, int, void *, void *, int, int);

extern "C" unsigned int function_7d8ec0(Object25 *object25, Object24 *object24) {
    return function_7d9370(object24, *object25->field_0, 0, 0, 0, 2);
}
