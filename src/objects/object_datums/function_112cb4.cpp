extern __declspec(thread) void * tls_150;

extern "C" void function_112cb4(void * state) {
    tls_150 = state;
}
