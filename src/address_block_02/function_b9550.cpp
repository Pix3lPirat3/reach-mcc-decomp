extern __declspec(thread) void * tls_200;

extern "C" void function_b9550(void * state) {
    tls_200 = state;
}
