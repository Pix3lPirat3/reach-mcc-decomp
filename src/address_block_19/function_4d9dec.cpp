extern __declspec(thread) void * tls_360;

extern "C" void function_4d9dec(void * state) {
    tls_360 = state;
}
