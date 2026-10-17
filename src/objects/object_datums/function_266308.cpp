struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_218;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_266308(block_owner * owner) {
    tls_218 = 0;
    function_a0274(3, owner->handle);
}
