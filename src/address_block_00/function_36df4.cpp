extern "C" bool function_36df4(void* object, int kind, void** result) {
    void* found = kind == 4 ? object : nullptr;
    *result = found;
    return found != nullptr;
}
