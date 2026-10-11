static_assert(sizeof(void*) == 8 && sizeof(int) == 4);
extern "C" int relative_heap_allocate_68a270(unsigned char* heap, int a, long long size);

extern "C" bool target_68a470(unsigned char* heap, unsigned char** out, long long size) {
    bool ok = false;
    const int offset = relative_heap_allocate_68a270(heap, 0, size);
    if (offset != 0) {
        *out = heap + static_cast<unsigned int>(offset);
        ok = true;
    }
    return ok;
}
