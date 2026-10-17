extern __declspec(thread) void * tls_290;

extern "C" void function_784dc(void * state) {
    tls_290 = state;
}
