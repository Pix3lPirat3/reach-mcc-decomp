struct slot {
    int next;
    int field_4;
};

struct slot_pool {
    slot slots[0x1000];
    unsigned char reserved8000[0x4000];
    int field_c000;
    int field_c004;
    int field_c008;
    int field_c00c;
    int field_c010;
    int field_c014;
};

extern "C" int function_68b0d4(slot_pool* pool) {
    pool->field_c000 = 0;
    long long index = 0x1000;
    pool->field_c004 = 0;
    pool->field_c008 = (int)index;
    pool->field_c014 = -1;
    pool->field_c00c = -1;
    pool->field_c010 = -1;
    int previous;
    do {
        --index;
        pool->slots[index].field_4 = -1;
        pool->slots[index].next = -1;
        previous = pool->field_c014;
        pool->slots[index].next = previous;
        pool->field_c004 = pool->field_c004 + 1;
        pool->field_c014 = (int)index;
    } while (index != 0);
    return previous;
}
