extern __declspec(thread) void * tls_580;

extern "C" void function_d9d44(void * state) {
    tls_580 = state;
}
