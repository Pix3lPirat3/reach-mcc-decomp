struct child_entry {
    void* shape;
    unsigned char reserved8[0x18];
};

struct list_shape {
    unsigned char reserved0[0x10];
    child_entry* children;
};

extern "C" void* hkpListShape_getChildShape_884e60(list_shape* shape, int index) {
    return shape->children[index].shape;
}
