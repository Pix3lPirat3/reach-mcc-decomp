extern __declspec(thread) void * tls_560;

extern "C" void function_5d3b0(void * state) {
    tls_560 = state;
}
