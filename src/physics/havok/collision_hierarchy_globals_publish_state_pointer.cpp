extern __declspec(thread) void * tls_550;

extern "C" void function_14ffc0(void * state) {
    tls_550 = state;
}
