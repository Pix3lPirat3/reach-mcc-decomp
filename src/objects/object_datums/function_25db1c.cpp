extern __declspec(thread) void * tls_1d8;

extern "C" void function_25db1c(void * state) {
    tls_1d8 = state;
}
