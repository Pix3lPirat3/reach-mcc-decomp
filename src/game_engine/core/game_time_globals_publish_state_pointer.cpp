extern __declspec(thread) void * tls_a0;

extern "C" void function_5c1f8(void * state) {
    tls_a0 = state;
}
