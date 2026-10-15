extern __declspec(thread) void * tls_660;

extern "C" void function_9d138(void * state) {
    tls_660 = state;
}
