struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_f0;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_3d2dcc(block_owner * owner) {
    tls_f0 = 0;
    function_a0274(1, owner->handle);
}
