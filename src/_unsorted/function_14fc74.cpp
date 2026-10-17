extern __declspec(thread) void * tls_330;

extern "C" void function_14fc74(void * state) {
    tls_330 = state;
}
