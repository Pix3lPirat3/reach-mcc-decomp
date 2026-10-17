extern __declspec(thread) void * tls_658;

extern "C" void function_a744c(void * state) {
    tls_658 = state;
}
