struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_368;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_27c0b0(block_owner * owner) {
    tls_368 = 0;
    function_a0274(3, owner->handle);
}
