struct runtime_info {
    int size;
    int solver_result_count;
};

extern "C" void hkpRagdollLimitsData_getRuntimeInfo_8d7490(void*, void*, runtime_info* info) {
    info->solver_result_count = 3;
    info->size = 0x1C;
}
