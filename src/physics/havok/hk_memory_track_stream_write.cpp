struct hk_memory_track_stream {
    unsigned char reserved0[16];
    void* tracker;
};

extern "C" void function_878ae0(void* tracker, void* data, int size);

extern "C" int function_878d20(hk_memory_track_stream* stream, void* data, int size) {
    function_878ae0(stream->tracker, data, size);
    return size;
}
