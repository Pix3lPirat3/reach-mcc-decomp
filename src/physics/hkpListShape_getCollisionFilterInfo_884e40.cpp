struct child_entry {
    void* shape;
    int filter_info;
    unsigned char reservedc[0x14];
};

struct list_shape {
    unsigned char reserved0[0x10];
    child_entry* children;
};

extern "C" int hkpListShape_getCollisionFilterInfo_884e40(list_shape* shape, int index) {
    return shape->children[index].filter_info;
}
