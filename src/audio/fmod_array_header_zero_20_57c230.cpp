struct array_header {
    void* first;
    void* second;
    int third;
};

extern "C" array_header* fmod_array_header_zero_20_57c230(array_header* header) {
    header->first = nullptr;
    header->second = nullptr;
    header->third = 0;
    return header;
}
