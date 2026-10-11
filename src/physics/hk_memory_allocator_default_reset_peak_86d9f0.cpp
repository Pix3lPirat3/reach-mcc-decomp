struct default_allocator {
    unsigned char reserved0[0x10];
    long long field_10;
    long long field_18;
};

extern "C" long long hk_memory_allocator_default_reset_peak_86d9f0(default_allocator* allocator) {
    long long value = allocator->field_10;
    allocator->field_18 = value;
    return value;
}
