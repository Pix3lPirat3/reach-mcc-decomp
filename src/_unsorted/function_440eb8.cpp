struct request {
    int index;
    long long value;
};

extern "C" char function_440eb8(char* destination, char* source) {
    long long index = *(int*)source;
    *(long long*)(destination + index * 20 + 0x88) = *(long long*)(source + 4);
    return 1;
}
