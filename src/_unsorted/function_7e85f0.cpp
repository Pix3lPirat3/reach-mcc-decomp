struct Object2;
struct Object8;

struct Object2 {
    unsigned char reserved0[1];
};

struct Object8 {
    unsigned char reserved0[0x68];
    Object2* field_68;
};

extern "C" int function_81b4b0(void *);

extern "C" int function_7e85f0(Object8 *object8) {
    return function_81b4b0(object8->field_68);
}
