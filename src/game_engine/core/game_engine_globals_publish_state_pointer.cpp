extern __declspec(thread) void * tls_20;

extern "C" void function_784fc(void * state) {
    tls_20 = state;
}
