extern __declspec(thread) void * tls_3a0;

extern "C" void function_b9590(void * state) {
    tls_3a0 = state;
}
