extern __declspec(thread) void * tls_528;

extern "C" void function_b2330(void * state) {
    tls_528 = state;
}
