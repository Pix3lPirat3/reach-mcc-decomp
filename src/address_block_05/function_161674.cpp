extern "C" void * function_78932a(void *destination, int value, unsigned long long size);
extern __declspec(thread) void *tls_5c8;

extern "C" void * function_161674()
{
    return function_78932a(tls_5c8, 0, 0x1300);
}
