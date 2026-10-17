struct Object5;
struct Object;

struct Object5 {
    Object* field_0;
};

struct Object {
    unsigned char reserved0[1];
};

extern "C" int function_7b5020(void *);

extern "C" int function_7cd6e0(Object5 *object5) {
    return function_7b5020(object5->field_0);
}
