extern "C" long long* function_3385b4(char* object, long long* out) {
    int value = 0;
    switch (*reinterpret_cast<int*>(object + 0x91c)) {
    case 0:
        value = 0x20005b;
        break;
    case 1:
        value = 0x20005c;
        break;
    case 2:
        value = 0x20005d;
        break;
    case 3:
        value = 0x20005e;
        break;
    }
    *reinterpret_cast<int*>(out) = value;
    return out;
}
