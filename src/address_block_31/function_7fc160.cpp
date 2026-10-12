struct Object8;

struct Object8 {
    void * field_0;
};

extern "C" long long function_7e4a30(void *);

extern "C" long long function_7fc160(Object8 *object8) {
    return function_7e4a30(object8->field_0);
}
