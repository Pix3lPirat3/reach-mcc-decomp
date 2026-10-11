static_assert(sizeof(void*) == 8 && sizeof(long long) == 8);
struct AllocationInterface {
    virtual void* allocate(long long size) = 0;
};
extern "C" void relative_heap_init_68a4b0(void* heap, long long a1, long long a2, long long a3, AllocationInterface* allocator);

extern "C" void* target_68a094(long long a1, long long a2, long long a3, AllocationInterface* allocator) {
    void* const heap = allocator->allocate(a2 + 0x68);
    if (heap != nullptr) relative_heap_init_68a4b0(heap, a1, a2, a3, allocator);
    return heap;
}
