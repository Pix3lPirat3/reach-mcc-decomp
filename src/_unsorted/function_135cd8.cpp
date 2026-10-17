extern __declspec(thread) void * tls_1a0;

extern "C" void function_135cd8(void * state) {
    tls_1a0 = state;
}
