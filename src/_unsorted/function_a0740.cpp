extern __declspec(thread) void * tls_190;

extern "C" void function_a0740(void * state) {
    tls_190 = state;
}
