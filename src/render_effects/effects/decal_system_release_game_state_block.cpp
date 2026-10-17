struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_350;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_15f7a0(block_owner * owner) {
    tls_350 = 0;
    function_a0274(6, owner->handle);
}
