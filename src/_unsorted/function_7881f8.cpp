extern "C" long long crt_onexit_register_7881a8(void* handler);

extern "C" int function_7881f8(void* handler) {
    return (crt_onexit_register_7881a8(handler) != 0) - 1;
}
