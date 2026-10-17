struct source_object {
    unsigned char reserved0[0xB978];
    long long table[0x280];
    int count;
};

struct result_slot {
    int kind;
    int reserved4;
    long long value;
};

extern "C" char function_3807fc(source_object* source, int index, result_slot* result) {
    long long pointer = 0;
    if (index < 0)
        return 0;
    if (index >= source->count)
        return 0;
    long long slot = (long long)index + index;
    if (*(int*)&source->table[slot] == 0)
        pointer = source->table[slot + 1];
    result->kind = 3;
    result->value = pointer != 0 ? pointer + 0x14 : 0;
    return 1;
}
