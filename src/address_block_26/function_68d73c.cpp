extern __declspec(thread) void * tls_30;

extern "C" void function_68d73c(void * state) {
    tls_30 = state;
}
