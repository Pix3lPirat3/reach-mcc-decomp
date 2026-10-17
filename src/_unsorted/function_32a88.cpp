extern __declspec(thread) void * tls_420;

extern "C" void function_32a88(void * state) {
    tls_420 = state;
}
