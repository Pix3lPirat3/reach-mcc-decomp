struct Object5;
struct Object4;

struct Object5 {
    unsigned char reserved0[0xa0];
    unsigned char field_a0[16];
};

struct Object4 {
    unsigned char reserved0[1];
};

extern "C" long long function_7b9330(void *, int);

extern "C" long long function_7d1e50(Object5 *object5, int value) {
    return function_7b9330((Object4 *)&object5->field_a0[8], value);
}
