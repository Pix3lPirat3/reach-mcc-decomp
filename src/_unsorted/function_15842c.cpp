extern __declspec(thread) void * tls_620;

extern "C" void function_15842c(void * state) {
    tls_620 = state;
}
