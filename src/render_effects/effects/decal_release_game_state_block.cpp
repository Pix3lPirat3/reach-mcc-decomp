struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_540;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_22f09c(block_owner * owner) {
    tls_540 = 0;
    function_a0274(6, owner->handle);
}
