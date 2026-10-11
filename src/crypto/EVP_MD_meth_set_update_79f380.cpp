struct method {
    unsigned char reserved0[0x18];
    void* update_function;
};

extern "C" int EVP_MD_meth_set_update_79f380(method* target, void* value) {
    target->update_function = value;
    return 1;
}
