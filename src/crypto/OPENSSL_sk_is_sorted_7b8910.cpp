struct stack {
    int count;
    int reserved4;
    void* items;
    int sorted;
};

extern "C" int OPENSSL_sk_is_sorted_7b8910(stack* sk) {
    if (sk == 0)
        return 1;
    return sk->sorted;
}
