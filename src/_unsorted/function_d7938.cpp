extern __declspec(thread) void * tls_588;

extern "C" void function_d7938(void * state) {
    tls_588 = state;
}
