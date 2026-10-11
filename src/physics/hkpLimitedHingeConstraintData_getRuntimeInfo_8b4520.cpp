struct runtime_info {
    int size;
    int solver_result_count;
};

extern "C" void hkpLimitedHingeConstraintData_getRuntimeInfo_8b4520(void*, void*, runtime_info* info) {
    info->solver_result_count = 8;
    info->size = 0x48;
}
