extern __declspec(thread) void * tls_e0;

extern "C" void function_d2cdc(void * state) {
    tls_e0 = state;
}
