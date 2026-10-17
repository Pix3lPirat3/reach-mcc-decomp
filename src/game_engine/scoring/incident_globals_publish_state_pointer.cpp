extern __declspec(thread) void * tls_98;

extern "C" void function_109288(void * state) {
    tls_98 = state;
}
