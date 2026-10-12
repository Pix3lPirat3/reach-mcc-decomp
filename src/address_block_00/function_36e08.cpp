extern "C" bool function_36e08(void* object, int kind, void** result) {
    void* found = kind == 3 ? object : nullptr;
    *result = found;
    return found != nullptr;
}
