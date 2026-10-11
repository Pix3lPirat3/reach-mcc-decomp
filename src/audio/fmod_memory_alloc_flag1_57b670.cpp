extern "C" long long fmod_memory_alloc_57b1e0(void* heap, int first, long long second, unsigned third, unsigned fourth, char flag);

extern "C" long long fmod_memory_alloc_flag1_57b670(void* heap, int first, long long second, int third, int fourth) {
    return fmod_memory_alloc_57b1e0(heap, first, second, third, fourth, 1);
}
