struct memory_track_stream {
    unsigned char reserved0[0x10];
    void* track;
};

extern "C" void function_878c00(void* track);

extern "C" void function_878d40(memory_track_stream* stream) {
    return function_878c00(stream->track);
}
