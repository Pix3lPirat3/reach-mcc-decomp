struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_418;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_1ff330(block_owner * owner) {
    tls_418 = 0;
    function_a0274(3, owner->handle);
}
