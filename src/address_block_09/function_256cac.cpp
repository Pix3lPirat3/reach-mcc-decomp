extern __declspec(thread) void * tls_2e8;

extern "C" void function_256cac(void * state) {
    tls_2e8 = state;
}
