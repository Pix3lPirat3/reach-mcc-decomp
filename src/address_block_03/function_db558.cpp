extern __declspec(thread) void * tls_6d8;

extern "C" void function_db558(void * state) {
    tls_6d8 = state;
}
