extern __declspec(thread) void * tls_48;

extern "C" void function_56a68(void * state) {
    tls_48 = state;
}
