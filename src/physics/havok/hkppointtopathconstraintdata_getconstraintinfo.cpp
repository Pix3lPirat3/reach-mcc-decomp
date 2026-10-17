struct constraint_info {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    void* data;
    int size;
};

extern "C" void* function_8d6900(char* self, constraint_info* info) {
    info->size = 0x18;
    info->data = self + 0x18;
    info->field_0 = 0;
    info->field_4 = 0x190;
    info->field_8 = 7;
    info->field_C = 8;
    return self + 0x18;
}
