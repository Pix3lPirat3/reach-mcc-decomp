extern __declspec(thread) void * tls_1c0;

extern "C" void function_68b68c(void * state) {
    tls_1c0 = state;
}
