struct free_list;

struct free_list_allocator {
    unsigned char reserved0[0x468];
    long long field_468;
};

extern "C" int hk_free_list_release_pages_876b80(free_list* list);

extern "C" long long hk_free_list_allocator_destroy_free_list_86ea10(free_list_allocator* allocator, free_list* list) {
    hk_free_list_release_pages_876b80(list);
    long long end = allocator->field_468;
    long long next = (long long)list + 0x68;
    if (next != end)
        return next;
    allocator->field_468 = end - 0x68;
    return end - 0x68;
}
