struct map_entry {
    long long key;
    long long value;
};

struct map_base {
    map_entry* entries;
    int reserved8;
    int mask;
};

extern "C" long long hkMapBase_findKey_nonempty_675cf0(map_base* map, unsigned long long key) {
    int mask = map->mask;
    map_entry* entries = map->entries;
    unsigned int index = (int)(key >> 4) * 0x9E3779B1u & mask;
    long long position = index;
    long long found = entries[index].key;
    if (found == -1)
        return mask + 1;
    while (found != (long long)key) {
        index = index + 1 & mask;
        position = index;
        found = entries[index].key;
        if (found != -1)
            continue;
        return mask + 1;
    }
    return position;
}
