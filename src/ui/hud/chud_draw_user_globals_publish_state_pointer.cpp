extern __declspec(thread) void * tls_160;

extern "C" void function_2d844c(void * state) {
    tls_160 = state;
}
