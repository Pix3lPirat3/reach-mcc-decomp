extern __declspec(thread) void * tls_320;

extern "C" void function_2e780c(void * state) {
    tls_320 = state;
}
