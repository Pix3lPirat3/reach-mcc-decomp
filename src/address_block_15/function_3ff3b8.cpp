extern "C" long long function_3e92e0(void* item, void* writer);

extern "C" long long function_3ff3b8(void* writer, char* items) {
    long long remaining = 0x11;
    long long result;
    do {
        result = function_3e92e0(items, writer);
        items += 0x10;
        --remaining;
    } while (remaining != 0);
    return result;
}
