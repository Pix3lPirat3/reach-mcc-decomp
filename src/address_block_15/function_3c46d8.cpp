struct counters {
    int field_0;
    int reserved4;
    long long field_8;
    long long field_10;
    int reserved18;
    int field_1c;
    int field_20;
};

extern "C" long long network_throttle_window_update_3c4794(counters* block);

extern "C" long long function_3c46d8(counters* block, int amount) {
    long long result = network_throttle_window_update_3c4794(block);
    block->field_8 = block->field_8 + 1;
    block->field_10 = block->field_10 + amount;
    block->field_1c = block->field_1c + 1;
    block->field_20 = block->field_20 + amount;
    block->field_0 = amount;
    return result;
}
