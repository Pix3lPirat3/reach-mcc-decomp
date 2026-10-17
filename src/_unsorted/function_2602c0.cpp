extern __declspec(thread) void * tls_4e8;

extern "C" void function_2602c0(void * state) {
    tls_4e8 = state;
}
