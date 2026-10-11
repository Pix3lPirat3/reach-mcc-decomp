struct frame_info {
    int field_0;
    int field_4;
};

extern "C" frame_info* hk_memory_system_frame_info_default_86df80(frame_info* info) {
    info->field_0 = 0x32000;
    info->field_4 = 0x600000;
    return info;
}
