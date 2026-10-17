extern __declspec(thread) void * tls_3b8;

extern "C" void function_4db30c(void * state) {
    tls_3b8 = state;
}
