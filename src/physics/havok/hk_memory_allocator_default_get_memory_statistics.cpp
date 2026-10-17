struct allocator_block {
    unsigned char reserved0[0x10];
    long long field_10;
    long long field_18;
};

struct statistics_block {
    long long field_0;
    long long field_8;
    long long field_10;
    long long field_18;
};

extern "C" long long function_86d9b0(allocator_block* allocator, statistics_block* statistics) {
    statistics->field_0 = allocator->field_10;
    statistics->field_8 = allocator->field_10;
    long long value = allocator->field_18;
    statistics->field_10 = value;
    statistics->field_18 = 0;
    return value;
}
