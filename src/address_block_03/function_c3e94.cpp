extern __declspec(thread) void * tls_5a0;

extern "C" void function_c3e94(void * state) {
    tls_5a0 = state;
}
