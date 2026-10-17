struct state_block {
    char reserved_00[16];
    char byte_10;
};

extern __declspec(thread) state_block * tls_48;

extern "C" bool function_58b98(void)
{
    return tls_48->byte_10 == 1;
}
