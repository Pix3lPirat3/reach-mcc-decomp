extern __declspec(thread) void * tls_630;

extern "C" void function_6f85cc(void * state) {
    tls_630 = state;
}
