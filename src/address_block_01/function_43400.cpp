extern __declspec(thread) void * tls_118;

extern "C" void function_43400(void * state) {
    tls_118 = state;
}
