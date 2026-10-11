struct stack {
    int count;
};

extern "C" long long OPENSSL_sk_num_7b8a50(stack* sk) {
    if (sk == 0)
        return 0xFFFFFFFF;
    return (unsigned int)sk->count;
}
