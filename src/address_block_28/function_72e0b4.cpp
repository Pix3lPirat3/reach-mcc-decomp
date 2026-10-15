extern __declspec(thread) void * tls_3a8;

extern "C" void function_72e0b4(void * state) {
    tls_3a8 = state;
}
