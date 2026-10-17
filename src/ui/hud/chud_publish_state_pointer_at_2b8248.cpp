extern __declspec(thread) void * tls_5e8;

extern "C" void function_2b8248(void * state) {
    tls_5e8 = state;
}
