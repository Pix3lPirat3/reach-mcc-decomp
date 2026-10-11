struct runtime_info {
    int size;
    int solver_result_count;
};

extern "C" void hkpRagdollConstraintData_getRuntimeInfo_8b3600(void*, void*, runtime_info* info) {
    info->solver_result_count = 12;
    info->size = 0x74;
}
