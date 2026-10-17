struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_288;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_b8a08(block_owner * owner) {
    tls_288 = 0;
    function_a0274(8, owner->handle);
}
