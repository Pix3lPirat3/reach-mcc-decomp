extern __declspec(thread) void * tls_5b8;

extern "C" void function_2021e4(void * state) {
    tls_5b8 = state;
}
