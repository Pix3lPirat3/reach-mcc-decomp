struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_318;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_b2f80(block_owner * owner) {
    tls_318 = 0;
    function_a0274(8, owner->handle);
}
