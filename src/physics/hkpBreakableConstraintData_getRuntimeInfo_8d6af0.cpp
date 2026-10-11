struct breakable_data {
    unsigned char reserved0[0x38];
    unsigned short runtime_size;
    unsigned short solver_count;
};

struct runtime_info {
    int size;
    int solver_count;
};

extern "C" int hkpBreakableConstraintData_getRuntimeInfo_8d6af0(breakable_data* data, long long, runtime_info* info) {
    info->solver_count = data->solver_count;
    int size = data->runtime_size + 0x34;
    info->size = size;
    return size;
}
