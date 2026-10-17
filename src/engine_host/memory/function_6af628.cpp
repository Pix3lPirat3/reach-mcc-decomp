struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_8;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_6af628(block_owner * owner) {
    tls_8 = 0;
    function_a0274(1, owner->handle);
}
