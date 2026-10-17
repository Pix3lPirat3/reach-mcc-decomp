extern __declspec(thread) void * tls_70;

extern "C" void function_cdf64(void * state) {
    tls_70 = state;
}
