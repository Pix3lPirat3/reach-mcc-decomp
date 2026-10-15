extern __declspec(thread) void * tls_230;

extern "C" void function_82fe4(void * state) {
    tls_230 = state;
}
