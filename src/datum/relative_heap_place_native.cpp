static_assert(sizeof(void*) == 8 && sizeof(long long) == 8);
extern "C" int relative_heap_init_68a4b0(void* heap, long long name, long long size, long long callback, long long owner);

extern "C" void* target_68a138(long long name, void* heap, unsigned long long total) {
    void* result = nullptr;
    const long long size = total <= 0x68 ? 0 : static_cast<long long>(total - 0x68);
    if (size != 0) {
        result = heap;
        relative_heap_init_68a4b0(heap, name, size, 0, 0);
    }
    return result;
}
