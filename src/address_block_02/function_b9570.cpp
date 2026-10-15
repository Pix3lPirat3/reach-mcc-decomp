extern __declspec(thread) void * tls_4f8;

extern "C" void function_b9570(void * state) {
    tls_4f8 = state;
}
