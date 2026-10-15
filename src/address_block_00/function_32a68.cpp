extern __declspec(thread) void * tls_110;

extern "C" void function_32a68(void * state) {
    tls_110 = state;
}
