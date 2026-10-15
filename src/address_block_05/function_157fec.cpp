extern "C" void * function_78932a(void * block, int value, unsigned long long size);

extern __declspec(thread) void * tls_648;

extern "C" void * function_157fec(void)
{
    return function_78932a(tls_648, 0, 0x80);
}
