extern __declspec(thread) void * tls_3c0;

extern "C" void function_46a140(void * state) {
    tls_3c0 = state;
}
