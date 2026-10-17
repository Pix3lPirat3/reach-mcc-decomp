extern __declspec(thread) void * tls_78;

extern "C" void function_d2d1c(void * state) {
    tls_78 = state;
}
