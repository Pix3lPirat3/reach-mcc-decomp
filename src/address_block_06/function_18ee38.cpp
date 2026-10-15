extern __declspec(thread) void * tls_1c8;

extern "C" void function_18ee38(void * state) {
    tls_1c8 = state;
}
