extern __declspec(thread) void * tls_220;

extern "C" void function_3ebe10(void * state) {
    tls_220 = state;
}
