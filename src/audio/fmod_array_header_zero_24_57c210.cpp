struct array_header {
    void* first;
    void* second;
    void* third;
};

extern "C" array_header* fmod_array_header_zero_24_57c210(array_header* header) {
    header->first = nullptr;
    header->second = nullptr;
    header->third = nullptr;
    return header;
}
