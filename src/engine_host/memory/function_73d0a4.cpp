struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_300;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_73d0a4(block_owner * owner) {
    tls_300 = 0;
    function_a0274(1, owner->handle);
}
