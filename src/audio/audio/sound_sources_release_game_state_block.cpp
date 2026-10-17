struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_90;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_2e358(block_owner * owner) {
    tls_90 = 0;
    function_a0274(8, owner->handle);
}
