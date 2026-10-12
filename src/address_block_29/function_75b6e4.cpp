struct object_c {
    unsigned char reserved0[4];
    float field_4;
};

struct object_d {
    unsigned char reserved0[2];
    unsigned short field_2;
};
extern "C" bool function_75b6e4(long long, long long, object_c* input, object_d* extra) {
    extra->field_2 = (unsigned short)((int)input->field_4);
    return true;
}
