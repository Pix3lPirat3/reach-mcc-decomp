extern __declspec(thread) void * tls_680;

extern "C" void function_2af470(void * state) {
    tls_680 = state;
}
