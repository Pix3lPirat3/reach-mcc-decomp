struct bn_gencb {
    int version;
    void* arg;
    void* callback;
};

extern "C" void BN_GENCB_set_7a5830(bn_gencb* gencb, void* callback, void* arg) {
    gencb->version = 2;
    gencb->arg = arg;
    gencb->callback = callback;
}
