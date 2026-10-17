extern __declspec(thread) void * tls_628;

extern "C" void function_153bd0(void * state) {
    tls_628 = state;
}
