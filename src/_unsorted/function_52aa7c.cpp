extern __declspec(thread) void * tls_670;

extern "C" void function_52aa7c(void * state) {
    tls_670 = state;
}
