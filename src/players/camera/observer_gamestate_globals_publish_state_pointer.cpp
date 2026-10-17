extern __declspec(thread) void * tls_5d8;

extern "C" void function_c775c(void * state) {
    tls_5d8 = state;
}
