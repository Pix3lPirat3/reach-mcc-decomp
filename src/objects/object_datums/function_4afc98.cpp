extern __declspec(thread) void * tls_1f8;

extern "C" void function_4afc98(void * state) {
    tls_1f8 = state;
}
