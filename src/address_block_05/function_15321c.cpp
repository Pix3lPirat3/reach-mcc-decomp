extern __declspec(thread) void * tls_4d0;

extern "C" void function_15321c(void * state) {
    tls_4d0 = state;
}
