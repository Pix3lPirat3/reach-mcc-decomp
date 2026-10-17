extern __declspec(thread) void * tls_590;

extern "C" void function_46a100(void * state) {
    tls_590 = state;
}
