struct block_owner {
    unsigned char reserved0[8];
    int handle;
};

extern __declspec(thread) void * tls_228;

extern "C" void function_a0274(int kind, int handle);

extern "C" void function_6ffa90(block_owner * owner) {
    tls_228 = 0;
    function_a0274(1, owner->handle);
}
