struct cache_backend {
    unsigned char reserved0[0x18];
    void* heap;
};

extern "C" long long relative_heap_delete_68a104(void* heap);

extern "C" long long c_fallback_optional_cache_backend__dispose_1d1c1c(cache_backend* backend) {
    long long result = relative_heap_delete_68a104(backend->heap);
    backend->heap = 0;
    return result;
}
