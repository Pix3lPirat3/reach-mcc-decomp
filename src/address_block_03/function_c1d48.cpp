struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_c8;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_c1d48(block_owner * owner) {
    tls_c8 = 0;
    function_a0274(2, owner->handle);
}
