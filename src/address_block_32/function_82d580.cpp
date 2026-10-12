struct Object32;
struct Object30;

struct Object32 {
    unsigned char reserved0[1];
};

struct Object30 {
    unsigned char reserved0[1];
};

extern "C" void * function_79f250(void *);
extern "C" int function_85b010(void *, void *);

extern "C" int function_82d580(Object30 *object30, Object32 *object32) {
    return function_85b010(object32, function_79f250(object30));
}
