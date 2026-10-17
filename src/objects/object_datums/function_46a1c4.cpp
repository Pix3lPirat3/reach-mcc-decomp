extern __declspec(thread) void * tls_678;

extern "C" void function_46a1c4(void * state) {
    tls_678 = state;
}
