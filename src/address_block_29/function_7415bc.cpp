struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_380;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_7415bc(block_owner * owner) {
    tls_380 = 0;
    function_a0274(1, owner->handle);
}
