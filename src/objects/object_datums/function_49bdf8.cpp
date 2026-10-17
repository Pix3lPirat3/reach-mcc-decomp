extern __declspec(thread) void * tls_530;

extern "C" void function_49bdf8(void * state) {
    tls_530 = state;
}
