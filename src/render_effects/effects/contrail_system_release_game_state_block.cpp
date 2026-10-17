struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_2f8;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_1ff3e0(block_owner * owner) {
    tls_2f8 = 0;
    function_a0274(3, owner->handle);
}
