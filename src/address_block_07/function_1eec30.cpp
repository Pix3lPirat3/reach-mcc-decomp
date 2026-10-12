extern "C" char function_1eec30(long long, long long, char flags) {
    if ((flags & 2) == 0)
        return 0;
    if ((flags & 4) != 0)
        return 0;
    return 1;
}
