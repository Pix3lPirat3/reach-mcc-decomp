extern __declspec(thread) void * tls_5c0;

extern "C" void function_165a68(void * state) {
    tls_5c0 = state;
}
