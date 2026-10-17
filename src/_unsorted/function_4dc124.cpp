extern __declspec(thread) void * tls_2c0;

extern "C" void function_4dc124(void * state) {
    tls_2c0 = state;
}
