struct region_allocator {
    unsigned char reserved0[8];
    long long field_8;
    long long field_10;
    long long field_18;
    unsigned char reserved20[8];
    long long field_28;
};

struct memory_statistics {
    long long field_0;
    long long field_8;
    long long field_10;
    long long field_18;
};

extern "C" long long hk_region_allocator_get_memory_statistics_871340(region_allocator* region, memory_statistics* stats) {
    stats->field_0 = region->field_10 - region->field_8;
    stats->field_18 = region->field_10 - region->field_18;
    stats->field_8 = region->field_18 - region->field_8;
    long long total = region->field_28;
    stats->field_10 = total;
    return total;
}
