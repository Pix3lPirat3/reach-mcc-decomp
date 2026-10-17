struct Object1 {
    unsigned char reserved0[0x38];
    unsigned short field_38;
    unsigned char field_3a[1];
};

extern "C" Object1 * data_a28d40[];
extern "C" void * function_865e8(int, short, void *, unsigned char);
extern "C" void function_85de0(int, int);

extern "C" void function_199364(short function_index, int thread, unsigned char flag) {
    Object1 * entry = data_a28d40[function_index];
    void * args = function_865e8(thread, entry->field_38, entry->field_3a, flag);
    if (args) {
        function_85de0(thread, 0);
    }
}
