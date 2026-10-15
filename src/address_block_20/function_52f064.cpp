struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_2b8;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_52f064(block_owner * owner) {
    tls_2b8 = 0;
    function_a0274(4, owner->handle);
}
