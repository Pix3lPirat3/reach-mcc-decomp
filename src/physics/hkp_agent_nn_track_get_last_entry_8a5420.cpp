struct block_list {
    int used_size;
    int reserved4;
    char** blocks;
    int block_count;
};

extern "C" char* hkp_agent_nn_track_get_last_entry_8a5420(block_list* list) {
    return list->blocks[list->block_count - 1] + (unsigned int)(list->used_size - 0xA0);
}
