extern "C" long long hk_large_block_allocator_get_usable_size_8776d0(void*, long long* block) {
    return (block[-1] & -4) - 0x10;
}
