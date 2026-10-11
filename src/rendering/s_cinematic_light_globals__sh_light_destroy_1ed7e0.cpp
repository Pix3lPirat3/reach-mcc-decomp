struct object_payload {
    unsigned char reserved0[4];
    unsigned int flags;
};

extern "C" long long object_get_payload_by_type_mask_4739cc(int handle, unsigned int mask);

extern "C" object_payload* s_cinematic_light_globals__sh_light_destroy_1ed7e0(char* globals, int index, char force) {
    long long offset = (long long)index * 0x148;
    int handle = *(int*)(offset + globals + 0xCC);
    if (handle == -1)
        return (object_payload*)(long long)index;
    if (force != 0 || (*(unsigned char*)(offset + globals + 0xC8) & 1) == 0) {
        long long payload = object_get_payload_by_type_mask_4739cc(handle, 0xFFFFFFFF);
        if (payload != 0)
            ((object_payload*)payload)->flags &= 0xFF7FFFFF;
        *(int*)(offset + globals + 0xCC) = -1;
        return (object_payload*)payload;
    }
    return (object_payload*)(long long)index;
}
