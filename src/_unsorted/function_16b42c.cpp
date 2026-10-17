extern __declspec(thread) void * tls_280;

extern "C" void function_16b42c(void * state) {
    tls_280 = state;
}
