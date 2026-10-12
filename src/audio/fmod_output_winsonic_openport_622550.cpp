extern "C" int fmod_output_winsonic_openport_622550(void*, int index, long long id, int* first_out, int* rate_out, int* count_out, int* last_out) {
    if (index != 0)
        return 0x1F;
    if (id != -1)
        return 0x1F;
    *first_out = index;
    *rate_out = 0xBB80;
    *count_out = 2;
    *last_out = 5;
    return 0;
}
