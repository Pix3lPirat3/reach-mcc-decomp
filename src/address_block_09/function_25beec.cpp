extern __declspec(thread) void * tls_b8;

extern "C" void function_25beec(void * state) {
    tls_b8 = state;
}
