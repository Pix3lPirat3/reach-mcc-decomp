struct world {
    unsigned char reserved0[0x130];
    int access_depth;
};

extern "C" long long hk_referenced_object_lock_all_86ccf0();

extern "C" long long hkp_world_enter_access_scope_8ab370(world* self) {
    long long result = hk_referenced_object_lock_all_86ccf0();
    self->access_depth = self->access_depth + 1;
    return result;
}
