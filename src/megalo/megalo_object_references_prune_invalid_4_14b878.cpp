extern "C" long long object_get_payload_by_type_mask_4739cc(int object_index, unsigned int type_mask);

extern "C" char megalo_object_references_prune_invalid_4_14b878(int* object_index) {
    char pruned = 0;
    long long remaining = 4;
    do {
        if (*object_index != -1 && object_get_payload_by_type_mask_4739cc(*object_index, 0xFFFFFFFFu) == 0) {
            *object_index = -1;
            pruned = 1;
        }
        object_index++;
        --remaining;
    } while (remaining != 0);
    return pruned;
}
