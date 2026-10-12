struct inner {
    char reserved0[0x44];
    int pending;
};

struct owner {
    char reserved0[0x50];
    inner* current;
};

extern "C" void* c_tag_resource_page_table__poll_pending_page_requests_239d80(owner* self, void* progress);

extern "C" inner* function_23a8c4(owner* self, void* progress) {
    inner* current = self->current;
    while (current->pending != 0) {
        c_tag_resource_page_table__poll_pending_page_requests_239d80(self, progress);
        current = self->current;
    }
    return current;
}
