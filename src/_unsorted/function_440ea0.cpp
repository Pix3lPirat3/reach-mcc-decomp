struct entry {
    int first;
    int second;
};

struct table {
    unsigned char reserved0[0x88];
    entry entries[1];
};

struct output {
    int index;
    entry value;
};

extern "C" long long function_440ea0(table* source, int index, output* destination) {
    destination->index = index;
    entry* item = (entry*)((char*)source->entries + (long long)index * 20);
    long long value = *(long long*)item;
    *(long long*)&destination->value = value;
    return value;
}
