struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_128;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_124c50(block_owner * owner) {
    tls_128 = 0;
    function_a0274(4, owner->handle);
}
