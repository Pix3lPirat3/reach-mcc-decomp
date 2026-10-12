extern "C" void* function_3178a0(char* object) {
    *reinterpret_cast<short*>(object + 4) = 0;
    object[0xC] = 0;
    *reinterpret_cast<long long*>(object + 0x1C2) = 0;
    *reinterpret_cast<long long*>(object + 0x1CA) = 0;
    return object;
}
