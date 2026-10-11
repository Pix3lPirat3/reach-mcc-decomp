struct openssl_stack {
    int count;
    unsigned char reserved4[4];
    void** items;
};

extern "C" void* OPENSSL_sk_value_7b8c80(openssl_stack* stack, int index) {
    if (stack == 0)
        return 0;
    if (index < 0)
        return 0;
    if (index >= stack->count)
        return 0;
    return stack->items[index];
}
