extern __declspec(thread) void * tls_1f0;

extern "C" void function_4da890(void * state) {
    tls_1f0 = state;
}
