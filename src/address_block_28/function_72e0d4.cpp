extern __declspec(thread) void * tls_5d0;

extern "C" void function_72e0d4(void * state) {
    tls_5d0 = state;
}
