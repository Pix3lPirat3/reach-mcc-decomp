extern __declspec(thread) void * tls_130;

extern "C" void function_43420(void * state) {
    tls_130 = state;
}
