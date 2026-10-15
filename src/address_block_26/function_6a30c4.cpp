struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_1b8;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_6a30c4(block_owner * owner) {
    tls_1b8 = 0;
    function_a0274(1, owner->handle);
}
