extern __declspec(thread) void * tls_140;

extern "C" void function_46a120(void * state) {
    tls_140 = state;
}
