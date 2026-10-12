extern "C" void *function_68c518();

extern "C" int function_68c5c4(int value) {
    void *local1;
    if (value == -1) {
        return -1;
    }
    local1 = function_68c518();
    int result = !local1 ? -1 : *(unsigned int *)((char *)local1 + 32);
    return result;
}
