struct region_allocator {
    unsigned char reserved0[8];
    int field_8;
    unsigned char reserved0c[4];
    int field_10;
};

extern "C" bool hk_region_allocator_can_allocate_871380(region_allocator* region, int size) {
    return size <= region->field_10 - region->field_8;
}
