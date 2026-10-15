extern __declspec(thread) void * tls_650;

extern "C" void function_d2d3c(void * state) {
    tls_650 = state;
}
