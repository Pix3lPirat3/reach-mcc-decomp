extern __declspec(thread) void * tls_1e0;

extern "C" void function_16203c(void * state) {
    tls_1e0 = state;
}
