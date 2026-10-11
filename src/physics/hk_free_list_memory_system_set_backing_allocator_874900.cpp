struct free_list_memory_system {
    unsigned char reserved0[8];
    void* field_8;
    unsigned char reserved10[0x20];
    void* field_30;
};

extern "C" void hk_free_list_memory_system_set_backing_allocator_874900(free_list_memory_system* system, void* allocator) {
    system->field_8 = allocator;
    system->field_30 = allocator;
}
