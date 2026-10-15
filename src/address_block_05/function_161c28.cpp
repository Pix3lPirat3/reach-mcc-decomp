extern __declspec(thread) void * tls_618;

extern "C" void function_161c28(void * state) {
    tls_618 = state;
}
