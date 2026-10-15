extern __declspec(thread) void * tls_488;

extern "C" void function_a0760(void * state) {
    tls_488 = state;
}
