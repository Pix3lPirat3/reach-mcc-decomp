struct child_object {
    unsigned char reserved0[0x30];
    void* field_30;
};

struct parent_object {
    unsigned char reserved0[0x10];
    child_object* child;
};

extern "C" void* hk_load_field_0x30_of_child_8eb1a0(parent_object* parent) {
    return parent->child->field_30;
}
