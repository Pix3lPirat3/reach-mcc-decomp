extern "C" bool function_36cb8(void* object, int kind, void** result) {
    void* found = kind == 2 ? object : nullptr;
    *result = found;
    return found != nullptr;
}
