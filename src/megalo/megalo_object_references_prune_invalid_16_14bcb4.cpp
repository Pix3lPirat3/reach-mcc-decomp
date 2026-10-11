extern "C" void* object_get_payload_by_type_mask_4739cc(int object_index, unsigned int type_mask);

extern "C" char megalo_object_references_prune_invalid_16_14bcb4(int* references) {
    char pruned = 0;
    long long remaining = 16;
    do {
        if (*references != -1 && object_get_payload_by_type_mask_4739cc(*references, 0xffffffffu) == 0) {
            *references = -1;
            pruned = 1;
        }
        references++;
        --remaining;
    } while (remaining != 0);
    return pruned;
}
