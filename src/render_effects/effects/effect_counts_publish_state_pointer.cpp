extern __declspec(thread) void * tls_260;

extern "C" void function_115848(void * state) {
    tls_260 = state;
}
