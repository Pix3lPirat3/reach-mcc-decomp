struct size_class_allocator {
    unsigned char reserved0[0x1C0];
    long long field_1c0;
    unsigned char field_1c8;
    unsigned char reserved1c9[7];
    long long field_1d0;
};

extern "C" long long hk_size_class_allocator_ctor_870e90(size_class_allocator* allocator);

extern "C" size_class_allocator* function_6760e0(size_class_allocator* allocator) {
    hk_size_class_allocator_ctor_870e90(allocator);
    allocator->field_1c0 = 0;
    allocator->field_1c8 = 0;
    allocator->field_1d0 = 0;
    return allocator;
}
