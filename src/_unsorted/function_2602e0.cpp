extern __declspec(thread) void * tls_400;

extern "C" void function_2602e0(void * state) {
    tls_400 = state;
}
