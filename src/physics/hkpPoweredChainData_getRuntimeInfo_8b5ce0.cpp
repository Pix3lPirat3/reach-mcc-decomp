struct chain_data {
    unsigned char reserved0[0x38];
    int link_count;
};

struct runtime_info {
    int size;
    int solver_result_count;
};

extern "C" int hkpPoweredChainData_getRuntimeInfo_8b5ce0(chain_data* data, void*, runtime_info* info) {
    int links = data->link_count;
    int results = links * 6;
    info->solver_result_count = results;
    int size = (links + 3 & -4) + (results + links * 2) * 8;
    info->size = size;
    return size;
}
