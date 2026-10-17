extern "C" bool function_68e08(long long, long long left, long long right) {
    if (*(long long*)(left + 0x10) != *(long long*)(right + 0x10))
        return false;
    if (*(int*)(left + 0x18) != *(int*)(right + 0x18))
        return false;
    return true;
}
