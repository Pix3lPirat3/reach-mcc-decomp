extern __declspec(thread) void * tls_d8;

extern "C" void function_5d390(void * state) {
    tls_d8 = state;
}
