extern "C" void* function_86c321(void* destination, const void* source, unsigned long long size);

struct entry {
    unsigned long long words[2];
    unsigned long long more_words[2];
};

struct entry_list {
    int count;
    int reserved4;
    entry entries[32];
};

extern "C" long long function_3e9e2c(entry_list* list, const entry* item) {
    int count = list->count;
    if (count == 32) {
        function_86c321(list->entries, list->entries + 1, 0x400);
        count = list->count - 1;
    }
    entry value = *item;
    list->count = count + 1;
    long long offset = (long long)count << 5;
    *(entry*)((char*)list + offset + 8) = value;
    return offset;
}
