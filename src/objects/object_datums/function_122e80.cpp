struct state_block {
    char reserved_00[0x31];
    char byte_31;
};

extern "C" void * function_13328(void * block);

extern __declspec(thread) state_block * tls_128;

extern "C" void * function_122e80(void)
{
    state_block * block = tls_128;
    block->byte_31 = 1;
    return function_13328(block);
}
