extern __declspec(thread) void * tls_448;

extern "C" void function_d2cfc(void * state) {
    tls_448 = state;
}
