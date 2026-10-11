struct class_info {
    unsigned char reserved0[0x28];
    char* members;
};

extern "C" char* hk_class_get_declared_member_879000(class_info* info, int index) {
    return info->members + (long long)index * 40;
}
