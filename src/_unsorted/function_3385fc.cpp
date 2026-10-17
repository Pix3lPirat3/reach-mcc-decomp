extern "C" long long* function_3385fc(char* object, long long* out) {
    int value = 0;
    switch (*reinterpret_cast<int*>(object + 0x920)) {
    case 0:
        value = 0x20005f;
        break;
    case 1:
        value = 0x200061;
        break;
    case 2:
        value = 0x200060;
        break;
    }
    *reinterpret_cast<int*>(out) = value;
    return out;
}
