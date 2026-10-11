struct parent_object {
    unsigned char reserved0[0x50];
    void** children;
};

extern "C" void* hk_get_child_pointer_by_index_9064a0(parent_object* parent, int index) {
    return parent->children[index];
}
