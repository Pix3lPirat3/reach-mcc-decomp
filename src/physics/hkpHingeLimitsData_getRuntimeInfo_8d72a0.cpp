struct runtime_info {
    int size;
    int solver_result_count;
};

extern "C" void hkpHingeLimitsData_getRuntimeInfo_8d72a0(void*, void*, runtime_info* info) {
    info->solver_result_count = 3;
    info->size = 0x1C;
}
