typedef int (*compare_function)(const void*, const void*);

struct stack_block {
    unsigned char reserved0[0x10];
    int field_10;
    unsigned char reserved14[4];
    compare_function field_18;
};

extern "C" compare_function OPENSSL_sk_set_cmp_func_7b8be0(stack_block* stack, compare_function compare) {
    compare_function previous = stack->field_18;
    stack->field_18 = compare;
    if (previous == compare)
        return previous;
    stack->field_10 = 0;
    return previous;
}
