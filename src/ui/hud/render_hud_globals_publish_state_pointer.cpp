extern __declspec(thread) void * tls_3d0;

extern "C" void function_25c6c4(void * state) {
    tls_3d0 = state;
}
