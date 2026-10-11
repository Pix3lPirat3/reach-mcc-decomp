extern "C" int start_pass_merged_upsample_54e140(char* decompressor) {
    char* upsample = *(char**)(decompressor + 0x248);
    upsample[0x48] = 0;
    int row_count = *(int*)(decompressor + 0x78);
    *(int*)(upsample + 0x50) = row_count;
    return row_count;
}
