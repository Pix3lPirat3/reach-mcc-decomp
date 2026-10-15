extern __declspec(thread) void * tls_6a0;

extern "C" void function_2af450(void * state) {
    tls_6a0 = state;
}
