struct statistics {
    unsigned char reserved0[0x10];
    void* world;
};

struct list_entry {
    unsigned char reserved0[0x20];
    unsigned char nested[1];
};

extern "C" void function_89cbc0(void* nested, void* world, void * stats);

extern "C" void function_889750(list_entry* entry, statistics* stats) {
    return function_89cbc0(entry->nested, stats->world, stats);
}
