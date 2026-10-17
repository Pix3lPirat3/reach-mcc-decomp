struct hash_map {
    unsigned char reserved0[8];
};

struct holder {
    unsigned char reserved0[0x10];
    hash_map map;
};

extern "C" long long hkMapBase_getWithDefault_676910(hash_map* map, unsigned long long key, long long fallback);

extern "C" char* function_873660(holder* self, char* out, int key) {
    *out = (int)hkMapBase_getWithDefault_676910(&self->map, key, 0) == 0;
    return out;
}
