struct Object44;
struct Object43;

struct Object44 {
    unsigned char reserved0[0x28];
    Object43* field_28;
};

struct Object43 {
    unsigned char reserved0[1];
};

extern "C" int function_807120(void *, void *);

extern "C" int function_7ec840(Object44 *object44, void * value) {
    return function_807120(object44->field_28, value);
}
