struct int_pair_source {
    int* first;
    int* second;
};

extern "C" long long function_910870(int_pair_source* source) {
    int* second = source->second;
    long long packed;
    *(int*)&packed = *source->first;
    *((int*)&packed + 1) = *second;
    return packed;
}
