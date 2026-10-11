extern "C" unsigned int pkey_ecx_ctrl_7d9080(long long key, int command) {
    (void)key;
    return command == 2 ? 1u : 0xFFFFFFFEu;
}
