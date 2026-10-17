struct inner_counts {
    unsigned char reserved0[0x10];
    long long first;
    long long second;
};

struct inner_object {
    unsigned char reserved0[0xD8];
    inner_counts* counts;
};

struct allocator_view {
    unsigned char reserved0[8];
    inner_object* inner;
};

struct memory_statistics {
    long long field_0;
    long long field_8;
    long long field_10;
    long long field_18;
};

extern "C" long long function_875a70(allocator_view* view, memory_statistics* stats) {
    stats->field_18 = 0;
    long long first = view->inner->counts->first;
    stats->field_8 = first;
    stats->field_0 = first;
    long long second = view->inner->counts->second;
    stats->field_10 = second;
    return second;
}
