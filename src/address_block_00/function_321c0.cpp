extern __declspec(thread) void * tls_298;

extern "C" void function_321c0(void * state) {
    tls_298 = state;
}
