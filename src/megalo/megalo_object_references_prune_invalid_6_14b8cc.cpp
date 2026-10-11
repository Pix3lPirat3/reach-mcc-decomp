extern "C" long long object_get_payload_by_type_mask_4739cc(int object_index, unsigned int type_mask);

extern "C" char megalo_object_references_prune_invalid_6_14b8cc(int* object_indices) {
    char pruned = 0;
    for (long long remaining = 6; remaining != 0; --remaining) {
        if (*object_indices != -1 && object_get_payload_by_type_mask_4739cc(*object_indices, 0xFFFFFFFFu) == 0) {
            *object_indices = -1;
            pruned = 1;
        }
        ++object_indices;
    }
    return pruned;
}
