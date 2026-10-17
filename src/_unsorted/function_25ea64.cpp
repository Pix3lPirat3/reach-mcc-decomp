extern __declspec(thread) void * tls_610;

extern "C" void function_25ea64(void * state) {
    tls_610 = state;
}
