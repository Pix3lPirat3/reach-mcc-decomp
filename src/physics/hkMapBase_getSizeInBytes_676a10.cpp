struct map_base {
    unsigned char reserved0[0xC];
    int field_C;
};

extern "C" int hkMapBase_getSizeInBytes_676a10(map_base* map) {
    return (map->field_C + 1) << 4;
}
