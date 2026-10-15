extern __declspec(thread) void * tls_4a8;

extern "C" void function_496434(void * state) {
    tls_4a8 = state;
}
