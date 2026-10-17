extern __declspec(thread) void * tls_510;

extern "C" void function_2602a0(void * state) {
    tls_510 = state;
}
