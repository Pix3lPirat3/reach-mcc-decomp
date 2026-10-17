extern __declspec(thread) void * tls_2d8;

extern "C" void function_dabec(void * state) {
    tls_2d8 = state;
}
