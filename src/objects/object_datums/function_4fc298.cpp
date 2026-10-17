struct target_record {
    unsigned char reserved0[0x1C];
};

extern "C" int function_4fc2b8(void * records, void * index);

extern "C" target_record* function_4fc298(target_record* records) {
    return records + function_4fc2b8(records, 0);
}
