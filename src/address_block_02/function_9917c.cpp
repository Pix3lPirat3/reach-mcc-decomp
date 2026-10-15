extern __declspec(thread) void * tls_5e0;

extern "C" void function_9917c(void * state) {
    tls_5e0 = state;
}
