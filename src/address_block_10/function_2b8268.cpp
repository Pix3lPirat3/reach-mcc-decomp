extern __declspec(thread) void * tls_5b0;

extern "C" void function_2b8268(void * state) {
    tls_5b0 = state;
}
