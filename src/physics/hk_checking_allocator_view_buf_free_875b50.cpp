struct checking_allocator_view {
    unsigned char reserved0[8];
    void* system;
    unsigned char tracker[1];
};

extern "C" long long hk_checking_memory_system_free_checked_875100(void* system, void* buffer, void* tracker, void* buffer_again, unsigned int total_size);

extern "C" long long hk_checking_allocator_view_buf_free_875b50(checking_allocator_view* view, void* buffer, int count, int element_size) {
    return hk_checking_memory_system_free_checked_875100(view->system, buffer, view->tracker, buffer, count * element_size);
}
