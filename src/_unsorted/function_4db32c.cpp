extern __declspec(thread) void * tls_578;

extern "C" void function_4db32c(void * state) {
    tls_578 = state;
}
