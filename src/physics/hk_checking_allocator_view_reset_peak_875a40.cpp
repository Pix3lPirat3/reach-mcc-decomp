struct counters {
    unsigned char reserved0[0x10];
    long long field_10;
    long long field_18;
};

struct checking_system {
    unsigned char reserved0[0xD8];
    counters* counters_ptr;
};

struct checking_allocator_view {
    unsigned char reserved0[8];
    checking_system* system;
};

extern "C" long long hk_checking_allocator_view_reset_peak_875a40(checking_allocator_view* view) {
    counters* current = view->system->counters_ptr;
    long long value = current->field_10;
    current->field_18 = value;
    return value;
}
