extern "C" long long world_entity_slot_clear_local_mapping_3dadd8(void* world, int entity_index, char flag);
extern "C" int world_entity_slot_release_sidecars_3db104(void* world, int entity_index);

extern "C" int c_replication_entity_manager__release_entity_slot_43cdcc(void** manager, int entity_index, char flag) {
    long long index = (unsigned long long)(unsigned int)(entity_index & 0x3ff) + 0xc;
    long long slot = index + index * 2;
    *((unsigned char*)manager + slot * 4) = *((unsigned char*)manager + slot * 4) | 2;
    *(int*)((unsigned char*)manager + slot * 4 + 8) = 0;
    world_entity_slot_clear_local_mapping_3dadd8(manager[0], entity_index, flag);
    long long result = world_entity_slot_release_sidecars_3db104(manager[0], entity_index);
    *((unsigned char*)manager + slot * 4) = *((unsigned char*)manager + slot * 4) & 0xf8;
    return (int)result;
}
